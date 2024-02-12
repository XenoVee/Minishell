/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 11:44:27 by rmaes         #+#    #+#                 */
/*   Updated: 2024/02/12 11:54:17 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

// creates a new t_dllist and copies over all the environment variables into it
t_dllist	*envcpy(char **envp)
{
	t_dllist	*env;
	int			i;
	char		**tmp;

	i = 0;
	env = cdl_listinit();
	if (env == NULL)
		error(ERR_MALLOC);
	while (envp[i])
	{
		tmp = ft_split(envp[i], '=');
		if (tmp == NULL)
			error(ERR_MALLOC);
		cdl_listaddback(env, cdl_nodenew(tmp[0], tmp[1]));
		free (tmp);
		i++;
	}
	return (env);
}
