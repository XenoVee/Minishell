/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getenv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 15:04:06 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/28 15:47:49 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static int	varlen(char *var)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != ' ' && var[i] != '\t' && var[i] != '\r'
		&& var[i] != '\n' && var[i] != '\v' && var[i] != '\f')
	{
		i++;
	}
	return (i);
}

// Finds variable var in the env list, and returns where in the list it is
// !!segfaults when var is NULL, ON PURPOSE, because that shouldnt happen
int	envsearch(t_dllist *env, char *var)
{
	t_dlnode		*node;
	unsigned int	explen;
	unsigned int	strlen;
	int				i;

	i = -1;
	node = env->head;
	strlen = varlen(var);
	explen = -1;
	while (node != env->head || i == -1)
	{
		if (i < 0)
			i = 0;
		explen = ft_strlen(node->name);
		if (strlen == explen)
			if (ft_strncmp(node->name, var, ft_max(explen, strlen)) == 0)
				return (i);
		i++;
		node = node->next;
	}
	return (-1);
}

t_dlnode	*ft_getenvnode(t_dllist *env, char *var)
{
	t_dlnode	*node;
	int			n;

	n = envsearch(env, var);
	if (n == -1)
		return (NULL);
	node = cdl_listgetnode(env, n);
	return (node);
}

char	*ft_getenv(t_dllist *env, char *var)
{
	t_dlnode	*node;

	node = ft_getenvnode(env, var);
	if (node == NULL)
		return (NULL);
	return (node->value);
}
