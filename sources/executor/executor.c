/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:06:32 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/08 14:27:58 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// int	executor(char *cmd, char **envp, char **argv)
// {
// 	char	*path;
// 	int		pid;

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		path = pathfinder(cmd);
// 		if (path == NULL)
// 			exit(1);
// 		if (access(path, X_OK) != 0)
// 			exit(2);
// 		if (execve(path, &argv[1], envp) == -1)
// 			perror("minishell");
// 		exit(1);
// 	}
// 	else
// 	{
// 		sleep(1);
// 		return (1);
// 	}
// }
