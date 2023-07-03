/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 20:42:45 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:51:03 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "structs.h"

void	init_data_fd(t_commands *cmd)
{
	if (!cmd->fd_data)
	{
		cmd->fd_data = malloc(sizeof * cmd->fd_data);
		if (!cmd->fd_data)
			return ;
		cmd->fd_data->infile = NULL;
		cmd->fd_data->outfile = NULL;
		cmd->fd_data->delim_hd = NULL;
		cmd->fd_data->quotes_hd = false;
		cmd->fd_data->fd_in = -1;
		cmd->fd_data->fd_out = -1;
	}
}

bool	init_data(t_data *data, char **env)
{
	data->token = NULL;
	data->env = envcpy(env);
	if (!data->env)
		return (NULL);
	data->user_input = NULL;
	data->cmd = NULL;
	g_exit_code = 0;
	return (true);
}
