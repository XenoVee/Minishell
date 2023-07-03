/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 10:42:34 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:50:34 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "expander.h"
#include "error.h"

char	*get_heredoc_name(void)
{
	static int	rand;
	char		*name;
	char		*rand_num;

	rand_num = ft_itoa(rand);
	if (!rand_num)
		return (NULL);
	name = ft_strjoin(HEREDOC_NAME, rand_num);
	free(rand_num);
	rand++;
	return (name);
}

char	*get_delim_hd(char *delim, bool	*quotes)
{
	int	size;

	size = ft_strlen(delim) - 1;
	if ((delim[0] == '\'' && delim[size] == '\'')
		|| (delim[0] == '\"' && delim[size] == '\"'))
	{
		*quotes = true;
		return (ft_strtrim(delim, "\'\""));
	}
	return (ft_strdup(delim));
}

char	*hd_expand_var(t_data *data, char *string)
{
	int			i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '$' && next_char_sep(string[i + 1]) == false
			&& var_between_quotes(string, i) == false)
			string = replace_str_hd(string,
					get_val(data, NULL, string + i), i);
		else
			i++;
	}
	return (string);
}

static char	*expand_var_hd(t_data *data, char *input)
{
	int		i;
	char	**words;

	words = ft_split(input, ' ');
	if (!words)
		return (NULL);
	i = 0;
	while (words[i])
	{
		if (ft_strchr(words[i], '$'))
		{
			words[i] = hd_expand_var(data, words[i]);
			if (words[i] == NULL)
				return (NULL);
		}
		i++;
	}
	return (reform_string(words));
}

bool	check_line_hd(t_data *data, t_data_fd *io, char **input, bool *ret)
{
	if (*input == NULL)
	{
		cmd_err_msg("warning", "heredoc delimited by EOF: wanted",
			io->delim_hd, true);
		*ret = true;
		return (false);
	}
	if (ft_strcmp(*input, io->delim_hd) == 0)
	{
		*ret = true;
		return (false);
	}
	if (io->quotes_hd == false && ft_strchr(*input, '$'))
	{
		*input = expand_var_hd(data, *input);
		if (!*input)
		{
			free_pointer(*input);
			*ret = false;
			return (false);
		}
	}
	return (true);
}
