/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 15:25:50 by rmaes         #+#    #+#                 */
/*   Updated: 2024/02/12 11:52:21 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "executor.h"
// I feel like I close pipes too often, might need changes, have to test
// especially with the in/outfile handlers

// runs in parent process
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

// runs in child process
// opens the pipes using dup(2);
// pipe: array of two file descriptors. pipe[0] is read, pipe[1] is write
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
