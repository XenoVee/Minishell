/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/27 16:12:45 by rmaes         ########   odam.nl         */
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

t_commands	*cmdmakewcl(void)
{
	t_commands	*cmd;
	char		**array;

	cmd = malloc(sizeof(t_commands));
	array = malloc(sizeof(char *) * 3);
	array[0] = ft_strdup("wc");
	array[1] = ft_strdup("-l");
	array[2] = NULL;
	cmd->args = array;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

t_commands	*cmdmakegrep(void)
{
	t_commands	*cmd;
	char		**array;

	cmd = malloc(sizeof(t_commands));
	array = malloc(sizeof(char *) * 3);
	array[0] = ft_strdup("grep");
	array[1] = ft_strdup("i");
	array[2] = NULL;
	cmd->args = array;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

t_commands	*cmdmakels(void)
{
	t_commands	*cmd;
	char		**array;

	cmd = malloc(sizeof(t_commands));
	array = malloc(sizeof(char *) * 3);
	array[0] = ft_strdup("ls");
	array[1] = ft_strdup("-FAG");
	array[2] = NULL;
	cmd->args = array;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

t_commands	*cmdmakeenv(void)
{
	t_commands	*cmd;
	char		**array;

	cmd = malloc(sizeof(t_commands));
	array = malloc(sizeof(char *) * 2);
	array[0] = ft_strdup("env");
	array[1] = NULL;
	cmd->args = array;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

t_commands	*cmdmakeecho(void)
{
	t_commands	*cmd;
	char		**array;

	cmd = malloc(sizeof(t_commands));
	array = malloc(sizeof(char *) * 3);
	array[0] = ft_strdup("echo");
	array[1] = ft_strdup("-n -n -n -n some words");
	// array[2] = ft_strdup("-m");
	// array[3] = ft_strdup("two");
	// array[4] = ft_strdup("things");
	array[2] = NULL;
	cmd->args = array;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

int	main(int argc, char **argv, char **envp)
{
	t_dllist	*env;
	t_commands	*cmd;

	cmd = cmdmakeecho();
	env = envcpy(envp);
	executor(cmd, env);
	// printf("%s\n", ft_getenv(env, "USER"));
	argc++;
	if (argv[0])
		;
}

// int yes(void)
// {
// 	printf("yes\n");
// 	return (1);
// }

// int no(void)
// {
// 	printf("no\n");
// 	return (0);
// }

// int	main(void)
// {
// 	if (yes() && no())
// 		;
// }
