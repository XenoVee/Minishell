/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc_utils2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 17:27:08 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:42:47 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "expander.h"

char	*reform_string(char **words)
{
	char	*string;
	char	*temp;
	int		i;

	i = -1;
	while (words[++i])
	{
		temp = string;
		if (i == 0)
			string = ft_strdup(words[0]);
		else
		{
			string = ft_strjoin(temp, words[i]);
			free_pointer(temp);
		}
		if (words[i + 1])
		{
			temp = string;
			string = ft_strjoin(temp, " ");
			free_pointer(temp);
		}
	}
	free_str_arr(words);
	return (string);
}

char	*erase_replace_var_hd(char *string, char *var, int index)
{
	char	*new;
	int		size;

	size = (ft_strlen(string) - var_length(string + index) + ft_strlen(var));
	new = get_new_string(string, var, size, index);
	return (new);
}

char	*replace_str_hd(char *string, char *var, int index)
{
	char	*temp;

	temp = NULL;
	if (var == NULL)
		*string = '\0';
	else
	{
		temp = string;
		string = erase_replace_var_hd(string, var, index);
		free_pointer(temp);
	}
	free_pointer(var);
	return (string);
}
