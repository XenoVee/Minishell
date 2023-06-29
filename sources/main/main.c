/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/29 17:49:22 by rmaes         ########   odam.nl         */
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

t_commands	*cmdmakeexit(void)
{
	t_commands	*cmd;
	char		**array;

	cmd = malloc(sizeof(t_commands));
	array = malloc(sizeof(char *) * 4);
	array[0] = ft_strdup("exit");
	array[1] = ft_strdup("a");
	array[2] = ft_strdup("20");
	array[3] = NULL;
	cmd->args = array;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

void	leaks(void)
{
	system("leaks -q minishell");
}

void	cmdclear(t_commands *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i])
	{
		free (cmd->args[i]);
		i++;
	}
	free (cmd->args);
	free (cmd);
}

int	main(int argc, char **argv, char **envp)
{
	t_dllist	*env;
	t_commands	*cmd;
	// t_commands	*cmd2;
	// t_commands	*cmd3;

	// atexit(leaks);
	env = envcpy(envp);
	cmd = cmdmakeexit();
	// cmd2 = cmdmakeenv();
	// cmd3 = cmdmakeunset();
	executor(cmd, env);
	argc++;
	if (argv[0])
		;
	cdl_listclear(env);
	cmdclear(cmd);
	// cmdclear(cmd2);
	// cmdclear(cmd3);
}
