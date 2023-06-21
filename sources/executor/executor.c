/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:06:32 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/21 16:10:43 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

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

static int	execute(char **cmd, t_dllist *env)
{
	char	*path;
	int		pid;
	char	**envp;

	pid = fork();
	if (pid == 0)
	{
		path = pathfinder(cmd[0]);
		ft_printf("%s\n", path);
		if (path == NULL)
			exit(1);
		envp = arrayize(env);
		if (access(path, X_OK) != 0)
			exit(2);
		if (execve(path, &cmd[0], envp) == -1)
			perror("minishell");
		exit(1);
	}
	else
	{
	}
	return (0);
}

int	executor(char **cmd1, t_dllist *env)
{
	execute(cmd1, env);
	wait(NULL);
	return (1);
}
