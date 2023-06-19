/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 14:14:33 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/14 13:51:30 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

static char	**envcpy_ignore(char **envp, int ignore)
{
	int		i;
	int		j;
	char	**envpc;

	envpc = ft_calloc(n_env(envp), sizeof(char *));
	if (envpc == NULL)
		error(ERR_MALLOC);
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (i == ignore)
		{
			free (envp[i]);
			i++;
		}
		envpc[j] = envp[i];
		i++;
		j++;
	}
	free (envp);
	return (envpc);
}

void	bi_unset(char *var, char ***envp)
{
	*envp = envcpy_ignore(*envp, envsearch(*envp, var));
}
