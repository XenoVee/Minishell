/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 14:14:33 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/08 15:44:10 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	bi_unset(char *var, char **envp)
{
	int		i;

	i = envsearch(envp, var);
	if (i == -1)
		return ;
	while (envp[i])
	{
		envp[i] = envp[i + 1];
		i++;
	}
}
