/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:06:32 by rmaes         #+#    #+#                 */
/*   Updated: 2023/05/15 15:29:47 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static int	execute(char **cmd, char **envp)
{
	char	*path;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		path = pathfinder(cmd[0]);
		if (path == NULL)
			exit(1);
		if (access(path, X_OK) != 0)
			exit(2);
		ft_printf("%s\n", path);
		ft_printf("%s |-| %s |-| %s\n", cmd[0], cmd[1], cmd[2]);
		if (execve(path, &cmd[0], envp) == -1)
			perror("minaishell");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

int	executor(char **cmd1, char **envp)
{
	// int	fd_b[2];
	// int	fd_pipe[2];

	// pipe(fd_pipe);
	// fd_b[0] = dup(1);
	// fd_b[1] = dup(0);
	// dup2(fd_pipe[0], 1);
	// dup2(fd_pipe[1], 0);
	ft_printf("%s\n", cmd1[0]);
	execute(cmd1, envp);
	// cmd2 = NULL;
	// execute(cmd2, envp, argv);
	// dup2(fd_b[0], 1);
	// dup2(fd_b[1], 0);
	// write(1, "test", 4);
	return (1);
}
