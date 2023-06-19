/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 11:15:03 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/19 14:37:12 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

static int	findequal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

static char	*validate(char *str)
{
	int		i;
	char	*ret;

	i = findequal(str);
	if (i == 0)
		return (NULL);
	ret = malloc(sizeof(char) * i);
	ft_memcpy(ret, str, i);
	ret[i] = '\0';
	return (ret);
}

static char	**envcpy_replace(char **envp, char *var, int replace)
{
	int		i;
	int		j;
	char	**envpc;

	envpc = ft_calloc(n_env(envp) + 1, sizeof(char *));
	if (envpc == NULL)
		error(ERR_MALLOC);
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (j == replace)
		{
			envpc[j] = var;
			free (envp[i]);
		}
		else
			envpc[j] = envp[i];
		i++;
		j++;
	}
	free (envp);
	return (envpc);
}

static char	**envcpy_add(char **envp, char *var, int pos)
{
	int		i;
	int		j;
	char	**envpc;

	envpc = ft_calloc(n_env(envp) + 2, sizeof(char *));
	if (envpc == NULL)
		error(ERR_MALLOC);
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (j == pos)
		{
			envpc[j] = var;
			j++;
		}
		envpc[j] = envp[i];
		i++;
		j++;
	}
	free (envp);
	return (envpc);
}

void	bi_export(char *var, char ***envp)
{
	int		n;
	char	*cutvar;

	cutvar = validate(var);
	printf("[%s]", cutvar);
	if (cutvar == NULL)
		exit(EXIT_FAILURE);
	n = envsearch(*envp, cutvar);
	if (n == -1)
		*envp = envcpy_add(*envp, ft_strdup(var), envsearch(*envp, "_"));
	else
		*envp = envcpy_replace(*envp, ft_strdup(var), n);
}
