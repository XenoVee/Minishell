/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 13:57:47 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/19 20:11:33 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Athena is taking over*/

int	env_var_count(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++:
	return (i);
}