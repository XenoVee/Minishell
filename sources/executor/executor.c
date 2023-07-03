/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:06:32 by rmaes         #+#    #+#                 */
/*   Updated: 2023/07/03 16:51:42 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

static int	builtin(t_commands *cmd, t_dllist *env)
{
	int	fd;

	fd = 2;
	if (!cmd->next && !cmd->prev && cmd->fd_data && cmd->fd_data->fd_out != -1)
		fd = cmd->fd_data->fd_out;
	if (!ft_strcmp("echo", cmd->args[0]))
		bi_echo(cmd, fd);
	else if (!ft_strcmp("cd", cmd->args[0]))
		bi_cd(env, cmd);
	else if (!ft_strcmp("pwd", cmd->args[0]))
		bi_pwd(fd);
	else if (!ft_strcmp("export", cmd->args[0]))
		bi_export(cmd, env, fd);
	else if (!ft_strcmp("unset", cmd->args[0]))
		bi_unset(cmd, env);
	else if (!ft_strcmp("env", cmd->args[0]))
		bi_env(env, fd);
	else if (!ft_strcmp("exit", cmd->args[0]))
		bi_exit(cmd);
	else
		return (0);
	return (1);
}

static void	child(t_commands *cmd, int *pipenew, int *pipeold, t_dllist *env)
{
	char	*path;
	char	**envp;

	printf("hi\n");
	startpipe(cmd, pipenew, pipeold);
	if (builtin(cmd, env))
		exit(0);
	else
	{
		path = pathfinder(cmd->args[0]);
		if (path == NULL)
			exit(1);
		envp = arrayize(env);
		if (access(path, X_OK) != 0)
			exit(2);
		if (execve(path, cmd->args, envp) == -1)
			perror("minishell");
		exit(1);
	}
}

static int	execute(t_commands *cmd, t_dllist *env, int *pipenew, int *pipeold)
{
	int		pid;

	if (cmd->next)
		pipe(pipenew);
	pid = fork();
	if (pid == 0)
		child(cmd, pipenew, pipeold, env);
	else
	{
		endpipe(cmd, pipenew, pipeold);
		wait(NULL);
	}
	return (0);
}

int	executor(t_commands *cmd, t_dllist *env)
{
	int	pipenew[2];
	int	pipeold[2];

	if (!(cmd->next) && builtin(cmd, env))
		return (0);
	else
	{
		while (cmd)
		{
			execute(cmd, env, pipenew, pipeold);
			cmd = cmd->next;
		}
	}
	return (0);
}
