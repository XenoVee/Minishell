/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 16:11:45 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:44:12 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include <stdlib.h>

/*figure this out, something aint right*/
int	count_length(char *string, int count, int i)
{
	int	status;

	status = DEFAULT;
	while (string[i])
	{
		if ((string[i] == '\'' || string[i] == '\"') && status == DEFAULT)
		{
			if (string[i] == '\'')
				status = S_QUOTES;
			else if (string[i] == '\"')
				status = D_QUOTES;
			i++;
			continue ;
		}
		else if ((string[i] == '\'' && status == S_QUOTES)
			|| (string[i] == '\"' && status == D_QUOTES))
		{
			status = DEFAULT;
			i++;
			continue ;
		}
		count++;
		i++;
	}
	return (count);
}

bool	remove_quotes(t_token **list)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = count_length((*list)->string, 0, 0);
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (false);
	while ((*list)->string[i])
	{
		if (((*list)->string[i] == '\'' || (*list)->string[i] == '\"') && (*list)->status == DEFAULT)
		{
			change_status_quote(list, &i);
			continue ;
		}
		else if (change_status_default(list, &i) == true)
			continue ;
		new[j++] = (*list)->string[i++];
	}
	new[j] = '\0';
	sort_strings(list, new);
	return (true);
}

bool	quotes_found(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\'' || string[i] == '\"')
			return (true);
		i++;
	}
	return (false);
}

bool	handle_quotes(t_data *data)
{
	t_token	*temp;

	temp = data->token;
	while (temp)
	{
		if (quotes_found(temp->string) == true)
			remove_quotes(&temp);
		temp = temp->next;
	}
	return (true);
}
