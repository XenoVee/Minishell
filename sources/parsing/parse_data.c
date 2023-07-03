/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 17:54:01 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 16:43:36 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>

void	handle_pipe(t_commands **cmds, t_token **list)
{
	t_commands	*last;

	last = lst_last_cmd(*cmds);
	last->pipe = true;
	lst_add_back_cmd(&last, lst_new_command(false));
	*list = (*list)->next;
}

static void	check_commands_empty(t_data *data)
{
	t_commands	*cmd;

	printf("checking commands\n");
	if (!data || !data->cmd)
	{
		if (!data)
			printf("no data\n");
		else if (!data->cmd)
			printf("no cmd\n");
		return ;
	}
	cmd = data->cmd;
	while (cmd && cmd->cmd)
	{
		if (!cmd->args)
		{
			cmd->args = malloc(sizeof * cmd->args * 2);
			cmd->args[0] = ft_strdup(cmd->cmd);
			cmd->args[1] = "\0";
		}
		cmd = cmd->next;
	}
}

void	parse_data(t_data *data, t_token *token)
{
	t_token	*temp;

	printf("it's time to parse data\n");
	if (token->type == END)
		return ;
	temp = token;
	while (temp->next != NULL)
	{
		//printf("new node\n");
		if (temp == token)
			lst_add_back_cmd(&data->cmd, lst_new_command(false));
		//printf("empty node made, ready to be filled. It does exist though!\n");
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
		{
			printf("it's done\n");
			break ;
		}
	}
	check_commands_empty(data);
	return ;
}
