/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/25 13:31:58 by rmaes         ########   odam.nl         */
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

void	leaks(void)
{
	system("leaks minishell -q");
}

int	main(int argc, char **argv, char **envp)
{
	t_dllist	*env;

	atexit (leaks);
	env = envcpy(envp);
	bi_cd(env, argv[1]);
	if (argv[1])
		;
	argc++;
	exit (EXIT_SUCCESS);
}

	// char *cmd1[3];
	// cmd1[0] = ft_strdup("ls");
	// cmd1[1] = ft_strdup("-la");
	// cmd1[2] = NULL;
	// char *cmd2[3];
	// cmd2[0] = ft_strdup("grep");
	// cmd2[1] = ft_strdup("Make");
	// cmd2[2] = NULL;
	// if (argc != 1)
	// 	executor(&argv[1], envp);
	// else
	// 	executort(cmd1, cmd2, envp);
	// return (0);

//lsof -c minishell
