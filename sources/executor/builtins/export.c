/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 11:15:03 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/25 13:35:48 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	bi_export(char *var, t_dllist *env)
{
	char	**s;
	int		i;

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
