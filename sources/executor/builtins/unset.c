/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 14:14:33 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/14 12:57:29 by rmaes         ########   odam.nl         */
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
	return (envpc);
}

void	swap(int un, char ***envp)
{
	char	**new;
	char	**tmp;

	new = envcpy_ignore(*envp, un);
	tmp = *envp;
	*envp = new;
	free (tmp);
}

void	bi_unset(char *var, char ***envp)
{
	swap(envsearch(*envp, var), envp);
}
