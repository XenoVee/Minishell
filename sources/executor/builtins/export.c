/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 11:15:03 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/25 14:57:55 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

static char	**sort_array(t_dllist *env)
{
	char	**cpy;
	char	*tmp;
	int		i;
	int		sorted;

	sorted = 0;
	i = 0;
	cpy = arrayize(env);
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < env->listlen - 1)
		{
			if (ft_strcmp(cpy[i], cpy[i + 1]) > 0)
			{
				tmp = cpy[i];
				cpy[i] = cpy[i + 1];
				cpy[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
	return (cpy);
}

static void	export_list(t_dllist *env)
{
	char **cpy;

	cpy = sort_array(env);
	int	i;
	i = 0;
	while (cpy[i])
	{
		printf("%s\n", cpy[i])
	}
}

void	bi_export(char *var, t_dllist *env)
{
	char	**s;
	int		i;

	if (var == NULL)
		export_list(env);
	s = ft_split(var, '=');
	i = envsearch(env, s[0]);
	if (i == -1)
	{
		cdl_listdecr(env);
		cdl_listaddback(env, cdl_nodenew(s[0], s[1]));
		cdl_listincr(env);
		free (s);
		return ;
	}
	else if (s[1])
	{
		env->current = cdl_listgetnode(env, i);
		free (env->current->value);
		free (s[0]);
		free (s);
		env->current->value = s[1];
		return ;
	}
	return ;
}
