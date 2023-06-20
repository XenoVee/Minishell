/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 14:14:33 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/20 14:10:44 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	bi_unset(char *var, t_dllist *env)
{
	int	i;

	i = envsearch(env, var);
	if (i == -1)
		exit(EXIT_FAILURE);
	cdl_listdelnode(env, i);
}
