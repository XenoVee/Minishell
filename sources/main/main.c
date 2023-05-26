/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/26 18:14:54 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int ac, char **av, char **envp)
{
	int	i;

	i = 0;
	if (argc < 2)
	{
		printf("try again\n");
		return (-1);
	}
	while (argv[i])
	{
		check_token(argv[i]);
		i++;
	}
	ft_printf("minishell\n");
	return (0);
}

//lsof -c minishell
