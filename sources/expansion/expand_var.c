/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_var.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 21:00:58 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 16:18:00 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "expander.h"
#include "minishell.h"
#include "cleanup.h"
#include <stdio.h>
#include <stdio.h>

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

char	*get_val(t_data *data, t_token *temp, char *string)
{
	char	*var;
	char	*value;

	var = id_variable(string);
	if (var && valid_var(data, var) == true)
	{
		if (temp)
			temp->valid_var = true;
		value = ft_getenv(data->env, var);
	}
	else if (var && var[0] == '?')
		value = ft_itoa(g_exit_code);
	else
		value = NULL;
	free_pointer(var);
	return (value);
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
				if (temp->string[i] == '$' && next_char_sep(temp->string[i + 1])
					== false && var_between_quotes(temp->string, i) == false
					&& (temp->status == DEFAULT || temp->status == D_QUOTES))
					replace_var(&temp,
						get_val(data, temp, temp->string + i), i);
				else
					i++;
			}
		}
		temp = temp->next;
	}
	return (handle_quotes(data) == false);
}
