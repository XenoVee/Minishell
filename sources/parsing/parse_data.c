/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 17:54:01 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/30 00:16:47 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	handle_pipe(t_commands *cmds, t_token **list)
{
	t_commands	*last;

	last = lst_last_cmd(*list);
	last->pipe = true;
	lst_add_back_cmd(&last, lst_new_command());
	*list = (*list)->next;
}

void	parse_data(t_data *data, t_token *token)
{
	t_token	*temp;

	if (token->type == END)
		return ;
	temp = token;
	while (temp->next != NULL)
	{
		if (temp == token)
			lst_add_back_cmd(&data->cmd, lst_new_command());
		if (temp->type == HEREDOC)
			parse_heredoc(data, &data->cmd, &temp);
		else if (temp->type == WORD || temp->type == VAR)
			parse_word(&data->cmd, &temp);
		else if (temp->type == INPUT)
			parse_input(&data->cmd, &temp);
		else if (temp->type == TRUNC)
			parse_trunc(&data->cmd, &temp);
		else if (temp->type == APPEND)
			parse_append(&data->cmd, &temp);
		else if (temp->type == PIPE)
			handle_pipe(&data->cmd, &temp);
		else if (temp->type == END)
			break ;
	}
	return ;
}
