/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:21:34 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/28 15:09:56 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libc.h>

static void	setpwd(t_dllist *env, char *n)
{
	char	*cwd;
	int		i;

	cwd = getcwd(NULL, 0);
	i = envsearch(env, n);
	if (i == -1)
	{
		cdl_listdecr(env);
		cdl_listaddback(env, cdl_nodenew(n, cwd));
		cdl_listincr(env);
	}
	else
	{
		env->current = cdl_listgetnode(env, i);
		if (env->current->value)
			free (env->current->value);
		env->current->value = cwd;
	}
}

static int	ereturn(char *rel)
{
	perror("minishell");
	if (rel)
		free (rel);
	return (1);
}

int	bi_cd(t_dllist *env, t_commands *cmd)
{
	char	*rel;

	setpwd(env, "OLDPWD");
	if (cmd->args[0] != NULL)
	{
		rel = getcwd(NULL, 0);
		rel = ft_realloc(rel, (ft_strlen(rel) + ft_strlen(cmd->args[1]) + 2));
		ft_strlcat(rel, "/", ft_strlen(rel) + 2);
		ft_strlcat(rel, cmd->args[1], (ft_strlen(rel)
				+ ft_strlen(cmd->args[1]) + 2));
		printf("%s\n", rel);
		if (chdir(rel) != 0 && chdir(cmd->args[0]) != 0)
			return (ereturn(rel));
		free (rel);
	}
	if (cmd->args[0] == NULL)
	{
		if (chdir(ft_getenv(env, "HOME")) != 0)
			return (ereturn(NULL));
	}
	setpwd(env, "PWD");
	return (0);
}
