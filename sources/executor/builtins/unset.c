/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 14:14:33 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/13 13:22:34 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

static void	intzero(int *i)
{
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
}

static char	**envcpy_ignore(char **envp, int ignore)
{
	int		i[3];
	char	**envpc;

	envpc = ft_calloc(n_env(envp), sizeof(char *));
	if (envpc == NULL)
		error(ERR_MALLOC);
	intzero(i);
	while (envp[i[OG]])
	{
		if (i[OG] == ignore)
			i[OG]++;
		envpc[i[CPY]] = malloc(ft_strlen(envp[i[OG]]) + 1);
		if (envpc[i[CPY]] == NULL)
			error(ERR_MALLOC);
		while (envp[i[OG]][i[CHAR]])
		{
			envpc[i[CPY]][i[CHAR]] = envp[i[OG]][i[CHAR]];
			i[CHAR]++;
		}
		envpc[i[CPY]][i[CHAR]] = '\0';
		i[CHAR] = 0;
		i[OG]++;
		i[CPY]++;
	}
	return (envpc);
}

void	swap(int un, char ***envp)
{
	char	**new;
	char	**tmp;
	int		i;

	new = envcpy_ignore(*envp, un);
	tmp = *envp;
	*envp = new;
	i = 0;
	while (tmp[i])
	{
		free (tmp[i]);
		i++;
	}
	free (tmp);
}

void	bi_unset(char *var, char ***envp)
{
	swap(envsearch(*envp, var), envp);
}
