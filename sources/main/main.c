/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/15 15:38:47 by rmaes         ########   odam.nl         */
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
	char **cmd1;
	cmd1 = malloc(sizeof(char *) * 3);
	cmd1[0] = strcpy(cmd1[0], "ls");
	ft_printf("aa\n");sTarry
	cmd1[1] = strcpy(cmd1[1], "-la");
	cmd1[2] = strcpy(cmd1[2], "\0");
	// char **cmd2;
	// cmd2 = malloc(sizeof(char *) * 3);
	// cmd2[0] = strcpy(cmd2[0], "grep");
	// cmd2[1] = strcpy(cmd2[1], "Make");
	// cmd2[2] = strcpy(cmd2[2], "\0");
	if (argc == 1)
		;// return (1);
	if (argv)
		;
	executor(cmd1, envp);
	return (0);
}

//lsof -c minishell
