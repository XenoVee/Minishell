/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:06:32 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/26 21:11:40 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

char	**arrayize(t_dllist *env)
{
	char	**array;
	int		i;
	int		len[2];

	i = 0;
	array = malloc(sizeof(char *) * (env->listlen + 1));
	array[env->listlen] = NULL;
	env->current = env->head;
	if (!array)
		error(ERR_MALLOC);
	while (env->current != env->head || i == 0)
	{
		len[NAME] = ft_strlen(env->current->name);
		len[VALUE] = ft_strlen(env->current->value);
		array[i] = malloc(sizeof(char) * (len[NAME] + len[VALUE] + 2));
		ft_strlcpy(array[i], env->current->name, len[NAME] + 1);
		ft_strlcat(array[i], "=", len[NAME] + 2);
		ft_strlcat(array[i], env->current->value, len[NAME] + len[VALUE] + 2);
		i++;
		env->current = env->current->next;
	}
	return (array);
}

static int	execute(t_commands *cmd, t_dllist *env, int *pipenew, int *pipeold)
{
	char	*path;
	int		pid;
	char	**envp;

	if (cmd->next)
		pipe(pipenew);
	pid = fork();
	if (pid == 0)
	{
		if (cmd->prev)
		{
			dup2(pipeold[0], STDIN);
			close(pipeold[0]);
			close(pipeold[1]);
		}
		if (cmd->next)
		{
			close(pipenew[0]);
			dup2(pipenew[1], STDOUT);
			close(pipenew[1]);
		}
		path = pathfinder(cmd->args[0]);
		if (path == NULL)
			exit(1);
		envp = arrayize(env);
		if (access(path, X_OK) != 0)
			exit(2);
		if (execve(path, cmd->args, envp) == -1)
			perror("minishell");
		exit(1);
	}
	else
	{
		if (cmd->prev)
		{
			close(pipeold[0]);
			close(pipeold[1]);
		}
		if (cmd->next)
		{
			pipeold[0] = pipenew[0];
			pipeold[1] = pipenew[1];
		}
		wait(NULL);
	}
	return (0);
}

int	single_builtin(t_commands *cmd)
{
	if (cmd->next)
		return (0);
	if (0 == (ft_strcmp("echo", cmd->args[0])
			* ft_strcmp("cd", cmd->args[0])
			* ft_strcmp("pwd", cmd->args[0])
			* ft_strcmp("export", cmd->args[0])
			* ft_strcmp("unset", cmd->args[0])
			* ft_strcmp("env", cmd->args[0])
			* ft_strcmp("exit", cmd->args[0])))
		return (1);
	return (0);
}

int	executor(t_commands *cmd, t_dllist *env)
{
	int	pipenew[2];
	int	pipeold[2];

	if (single_builtin(cmd))
	{
		printf("it works \n");
	}
	while (cmd)
	{
		execute(cmd, env, pipenew, pipeold);
		cmd = cmd->next;
	}
	return (5);
}
