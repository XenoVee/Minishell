/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 11:44:27 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/13 13:23:27 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

int	n_env(char **envp)
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
	// manage malloc fail
	i = 0;
	j = 0;
	while (envp[i])
	{
		envpc[i] = malloc(ft_strlen(envp[i]) + 1);
		// manage malloc fail
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
