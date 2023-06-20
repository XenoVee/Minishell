/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 11:15:03 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/20 14:58:10 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	export_list(t_dllist *env)
{
	exit(EXIT_FAILURE);
	env->current = env->head;
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
		exit(EXIT_SUCCESS);
	}
	else if (s[1])
	{
		env->current = cdl_listgetnode(env, i);
		free (env->current->value);
		env->current->value = s[1];
		exit(EXIT_SUCCESS);
	}
	else
		exit(EXIT_SUCCESS);
}
