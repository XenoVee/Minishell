/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 15:04:06 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/13 11:43:38 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static int	ft_explen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

char	*ft_getenv(char **envp, char *var)
{
	unsigned int	i;
	unsigned int	explen;
	unsigned int	strlen;

	i = 0;
	strlen = ft_strlen(var);
	while (envp[i])
	{
		explen = ft_explen(envp[i]);
		if (strlen == explen)
			if (ft_strncmp(envp[i], var, ft_max(explen, strlen)) == 0)
				return (&envp[i][strlen + 1]);
		i++;
	}
	return (NULL);
}
