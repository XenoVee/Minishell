/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/07/03 16:39:03 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "lexer.h"
#include "structs.h"
#include "loop.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "builtins.h"
#include <fcntl.h>

int g_exit_code = 0;


// t_commands	*cmdmakeenv(void)
// {
// 	t_commands	*cmd;
// 	char		**array;

// 	cmd = malloc(sizeof(t_commands));
// 	array = malloc(sizeof(char *) * 2);
// 	array[0] = ft_strdup("env");
// 	array[1] = NULL;
// 	cmd->args = array;
// 	cmd->next = NULL;
// 	cmd->prev = NULL;
// 	return (cmd);
// }

// t_commands	*cmdmakeunset(void)
// {
// 	t_commands	*cmd;
// 	char		**array;

// 	cmd = malloc(sizeof(t_commands));
// 	array = malloc(sizeof(char *) * 3);
// 	array[0] = ft_strdup("unset");
// 	array[1] = ft_strdup("TEST");
// 	array[2] = NULL;
// 	cmd->args = array;
// 	cmd->next = NULL;
// 	cmd->prev = NULL;
// 	return (cmd);
// }

// t_commands	*cmdmakeexport(void)
// {
// 	t_commands	*cmd;
// 	char		**array;

// 	cmd = malloc(sizeof(t_commands));
// 	array = malloc(sizeof(char *) * 4);
// 	array[0] = ft_strdup("export");
// 	array[1] = ft_strdup("TEST=var");
// 	array[2] = ft_strdup("VAR=test");
// 	array[3] = NULL;
// 	cmd->args = array;
// 	cmd->next = NULL;
// 	cmd->prev = NULL;
// 	return (cmd);
// }

// t_commands	*cmdmakels(void)
// {
// 	t_commands	*cmd;
// 	char		**array;

// 	cmd = malloc(sizeof(t_commands));
// 	array = malloc(sizeof(char *) * 3);
// 	array[0] = ft_strdup("ls");
// 	array[1] = ft_strdup("-FGA");
// 	array[2] = NULL;
// 	cmd->args = array;
// 	cmd->next = NULL;
// 	cmd->prev = NULL;
// 	return (cmd);
// }

// void	leaks(void)
// {
// 	system("leaks -q minishell");
// }

// void	cmdclear(t_commands *cmd)
// {
// 	int	i;

// 	i = 0;
// 	while (cmd->args[i])
// 	{
// 		free (cmd->args[i]);
// 		i++;
// 	}
// 	free (cmd->args);
// 	free (cmd);
// }

//int	second_main(int argc, char **argv, char **envp)
// {
// 	t_dllist	*env;
// 	t_commands	*cmd;
// 	t_commands	*cmd2;
// 	t_commands	*cmd3;

// 	// atexit(leaks);
// 	env = envcpy(envp);
// 	cmd = cmdmakeexport();
// 	cmd2 = cmdmakeenv();
// 	cmd3 = cmdmakeunset();
// 	cmd->next = cmd2;
// 	cmd2->prev = cmd;
// 	executor(cmd, env);
// 	argc++;
// 	if (argv[0])
// 		;
// 	cdl_listclear(env);
// 	cmdclear(cmd);
// 	cmdclear(cmd2);
// 	cmdclear(cmd3);
// }

int	main(int ac, char **av, char **env)
{
	t_data	data;

	// if (ac > 1)
	// {
	// 	second_main(ac, av, env);
	// 	return (1);
	// }
	(void)ac;
	(void)av;
	ft_memset(&data, 0, sizeof(t_data));
	if (!init_data(&data, env))
		exit_ms(NULL, 0);
	mini_loop(&data);
	return (0);
}
