/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:25:50 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/30 15:28:08 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "executor.h"

void	endpipe(t_commands *cmd, int *pipenew, int *pipeold)
{
	if (cmd->prev)
	{
		close(pipeold[0]);
		close(pipeold[1]);
	}
	if (cmd->next)
	{
		pipeold[0] = pipenew[0];
		pipeold[1] = pipenew[1];
	}
}

void	startpipe(t_commands *cmd, int *pipenew, int *pipeold)
{
	if (cmd->fd_data->fd_in != -1)
	{
		dup2(cmd->fd_data->fd_in, STDIN);
		close(pipeold[1]);
	}
	else if (cmd->prev)
	{
		dup2(pipeold[0], STDIN);
		close(pipeold[0]);
		close(pipeold[1]);
	}
	if (cmd->fd_data->fd_out != -1)
	{
		close(pipenew[0]);
		dup2(cmd->fd_data->fd_out, STDOUT);
	}
	else if (cmd->next)
	{
		close(pipenew[0]);
		dup2(pipenew[1], STDOUT);
		close(pipenew[1]);
	}
}