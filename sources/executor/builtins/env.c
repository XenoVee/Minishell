/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 13:45:01 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/08 14:36:14 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

void	bi_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		write (1, envp[i], ft_strlen(envp[i]));
		write (1, "\n", 1);
		i++;
	}
}
