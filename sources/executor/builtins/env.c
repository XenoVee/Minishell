/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 13:45:01 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/20 14:52:52 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdio.h>

void	bi_env(t_dllist *env)
{
	env->current = env->head;
	while (env->current->next != env->head)
	{
		if (env->current->value)
			printf("%s=%s\n", env->current->name, env->current->value);
		env->current = env->current->next;
	}
	if (env->current->value)
		printf("%s=%s\n", env->current->name, env->current->value);
}
