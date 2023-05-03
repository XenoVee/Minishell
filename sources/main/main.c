/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/03 14:29:45 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "minishell.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

// int	main(int argc, char *argv[], char *envp[])
// {
// 	int	fd[2];
// 	char *str;
// 	int	pid;

// 	pid = fork();
// 	ft_printf("%i\n", pid);
// 	if (pid == 0)
// 	{
// 		char	*array[2];
// 		array[0] = strdup("bonus");
// 		// array[1] = strdup("-la");
// 		array[1] = NULL;
// 		if (execve("/Users/rmaes/Projects/minitalk/server", NULL, envp) == -1)
// 			perror("ERROR");
// 		exit(0);
// 	}
// 	else
// 	{
// 		while (1) {
// 			ft_printf("test\n");
// 			sleep(1);
// 		}
// 	}
// 	close(fd[1]);
// 	close(fd[0]);
// 	exit(0);
// }

int	main(int argc, char **argv, char **envp)
{
	executor(argv[1], envp, argv);
}

//lsof -c minishell
