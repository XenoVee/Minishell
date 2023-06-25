/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:21:34 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/25 13:53:19 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libc.h>

static void	setpwd(t_dllist *env, char *n, int l)
{
	char	*cwd;
	char	*var;

	cwd = getcwd(NULL, 0);
	var = malloc(sizeof(char) * (ft_strlen(cwd) + l));
	ft_strlcpy(var, n, l);
	ft_strlcat(var, cwd, ft_strlen(cwd) + l);
	bi_export(var, env);
	free (var);
	free (cwd);
}

void	bi_cd(t_dllist *env, char *arg)
{
	setpwd(env, "OLDPWD=", 8);
	if (arg != NULL)
	{
		if (chdir(arg) != 0)
		{
			perror("minishell");
			return ;
		}
	}
	if (arg == NULL)
	{
		if (chdir(ft_getenv(env, "HOME")) != 0)
		{
			perror("minishell");
			return ;
		}
	}
	setpwd(env, "PWD=", 5);
	bi_env(env);
}
