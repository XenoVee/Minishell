/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/14 11:15:03 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/29 17:19:19 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

static char	**sort_array(t_dllist *env)
{
	char			**cpy;
	char			*tmp;
	unsigned long	i;
	int				sorted;

	sorted = 0;
	i = 0;
	cpy = arrayize(env);
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < env->listlen - 1)
		{
			if (ft_strcmp(cpy[i], cpy[i + 1]) < 0)
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

static void	export_list(t_dllist *env, int fd)
{
	char	**cpy;
	int		i;

	cpy = sort_array(env);
	i = 0;
	while (cpy[i])
	{
		write(fd, "declare -x ", 11);
		ft_putstr_fd(cpy[i], fd);
		i++;
	}
}

static void	addnewvar(t_dllist *env, char **s)
{
	cdl_listdecr(env);
	cdl_listaddback(env, cdl_nodenew(s[0], s[1]));
	cdl_listincr(env);
}

static void	editvar(t_dllist *env, char **s, int i)
{
	env->current = cdl_listgetnode(env, i);
	if (env->current->value)
		free (env->current->value);
	env->current->value = s[1];
	free (s[0]);
}

void	bi_export(t_commands *cmd, t_dllist *env, int fd)
{
	char	**s;
	int		n;
	int		i;

	i = 1;
	if (cmd->args[i] == NULL)
	{
		export_list(env, fd);
		return ;
	}
	while (cmd->args[i])
	{
		s = ft_split(cmd->args[i], '=');
		n = envsearch(env, s[0]);
		if (n == -1)
			addnewvar(env, s);
		else if (s[1])
			editvar(env, s, n);
		free (s);
		i++;
	}
}
