/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/15 14:57:08 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	char	*test;

	(void)ac;
	(void)av;
	printf("Start!\n");
	ft_memset(&data, 0, sizeof(t_data));
	if (!init_data(data))
		exit(FAILURE);
	mini_loop(&data);
	ft_printf("minishell\n");
	return (0);
}
// void	leaks(void)
// {
// 	system("leaks minishell -q");
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	executor(argv[1], envp, argv);
// }
