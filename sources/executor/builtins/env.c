/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 13:45:01 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/29 17:44:44 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdio.h>

static void	write_env(char *name, char *val, int fd)
{
	ft_putstr_fd(name, fd);
	write(fd, "=", 1);
	ft_putstr_fd(val, fd);
}

void	bi_env(t_dllist *env, int fd)
{
	env->current = env->head;
	while (env->current->next != env->head)
	{
		if (env->current->value)
			write_env(env->current->name, env->current->value, fd);
		env->current = env->current->next;
	}
	if (env->current->value)
		write_env(env->current->name, env->current->value, fd);
}
