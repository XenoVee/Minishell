/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 15:32:31 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:44:03 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "error.h"

int	save_word(t_token **lst, char *str, int index, int start)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (index - start + 1));
	if (!word)
		return (FAILURE);
	while (start < index)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	lst_add_back_tkn(lst, new_token(word, ft_strdup(word), WORD, DEFAULT));
	return (SUCCESS);
}

int	save_seperator(t_token **lst, char *str, int index, int type)
{
	int		i;
	char	*sep;

	i = 0;
	if (type == HEREDOC || type == APPEND)
	{
		sep = (char *)malloc(sizeof(char) * 3);
		if (!sep)
			return (FAILURE);
		while (i < 2)
		{
			sep[i] = str[index];
			i++;
			index++;
		}
		sep[i] = '\0';
		lst_add_back_tkn(lst, new_token(sep, ft_strdup(sep), type, DEFAULT));
	}
	else
	{
		sep = (char *)malloc(sizeof(char) * 2);
		if (!sep)
			return (FAILURE);
		sep[0] = str[index];
		sep[1] = '\0';
		lst_add_back_tkn(lst, new_token(sep, ft_strdup(sep), type, DEFAULT));
	}
	return (SUCCES);
}

int	id_type(char *str, int i)
{
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		return (SPACES);
	else if (str[i] == '|')
		return (PIPE);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (HEREDOC);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (APPEND);
	else if (str[i] == '<')
		return (INPUT);
	else if (str[i] == '>')
		return (TRUNC);
	else if (str[i] == '\0')
		return (END);
	else
		return (0);
}

int	save_part(t_data *data, int *i, char *str, int start)
{
	int	type;

	type = id_type(str, (*i));
	if (type)
	{
		if ((*i) != 0 && id_type(str, (*i) - 1) == 0)
			save_word(&data->token, str, (*i), start);
		if (type == PIPE || type == INPUT || type == TRUNC
			|| type == HEREDOC || type == APPEND || type == END)
		{
			save_seperator(&data->token, str, (*i), type);
			if (type == HEREDOC || type == APPEND)
				(*i)++;
		}
		start = (*i) + 1;
	}
	return (start);
}
