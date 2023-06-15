/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 14:14:33 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/08 14:38:59 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_unset(char *var, char **envp)
{
	char	*del;

	del = envsearch(envp, var);
}
