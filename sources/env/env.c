/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 11:44:27 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/13 12:02:56 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static int	n_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

char	**envcpy(char **envp)
{
	int		i;
	int		j;
	char	**envpc;

	envpc = ft_calloc(n_env(envp) + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (envp[i])
	{
		envpc[i] = malloc(ft_strlen(envp[i]) + 1);
		while (envp[i][j])
		{
			envpc[i][j] = envp[i][j];
			j++;
		}
		envpc[i][j] = '\0';
		j = 0;
		i++;
	}
	return (envpc);
}
