/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 14:14:33 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/28 15:45:03 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	bi_unset(t_commands *cmd, t_dllist *env)
{
	int	n;
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		n = envsearch(env, cmd->args[i]);
		if (n == -1)
			return ;
		cdl_listdelnode(env, n);
		i++;
	}
}
