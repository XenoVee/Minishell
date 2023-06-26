/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_var.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 21:00:58 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/26 14:19:47 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	update_status(t_token **node, char c)
{
	if (c == '\'' && (*node)->status == DEFAULT)
		(*node)->status = S_QUOTES;
	if (c == '\"' && (*node)->status == DEFAULT)
		(*node)->status = D_QUOTES;
	if (c == '\'' && (*node)->status == S_QUOTES)
		(*node)->status = DEFAULT;
	if (c == '\"' && (*node)->status == D_QUOTES)
		(*node)->status = DEFAULT;
}
/*sleepcoded, check later*/
bool	next_char_sep(char c)
{
	if (c == '$' || c == ' ' || c == '=' || c == '\0')
		return (true);
	return (false);
}

/*sleepcoded, check later*/
bool	var_between_quotes(char *string, int i)
{
	if (i > 0)
	{
		if (string[i - 1] == '\"' && string[i + 1] == '\"')
			return (true);
		return (false);
	}
	return (false);
}

/*sleepcoded, check later*/
int	expand_var(t_data *data, t_token **list)
{
	t_token		*temp;
	int			i;

	temp = *list;
	while (temp)
	{
		if (temp->type == VAR)
		{
			i = 0;
			while (temp->string[i])
			{
				update_status(&temp, temp->string[i]);
				if (temp->string[i] == '$' && next_char_sep(temp->string[i + 1]) == false
					&& var_between_quotes(temp->string, i) == false)
					replace_var(&temp, ft_getenv(data->env, temp->string + 1), i);
					/*Need something to do stuff idk, it's 1:49 and I need sleep*/
				else
					i++;
			}
		}
		temp = temp->next;
	}
	return (0);
}
