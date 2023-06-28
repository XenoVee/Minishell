/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_word.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 18:20:48 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/28 20:26:49 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "expander.h"


void	parse_word(t_commands **cmd, t_token **list)
{
	t_commands	*last;
	t_token		*temp;

	temp = *list;
	while (temp->type == WORD || temp->type == VAR)
	{
		last = lst_last_cmd(*cmd);
		if (temp->prev == NULL || (temp->prev && temp->prev->type == PIPE)
			|| last->args[0] == NULL)
		{
			if (temp->type == VAR)
		}
	}
}