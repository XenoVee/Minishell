/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:02:19 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/06 16:26:11 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static char	*cutvar(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] != ' ' && str[i])
	{
		i++;
	}
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		error(ERR_MALLOC);
	i = 0;
	while (str[i] != ' ' && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

static int	varhandler(char *print, int *j, char *str, char **envp)
{
	char	*var;
	char	*exp;
	int		i;

	var = cutvar(str);
	exp = expand(envp, var);
	i = 0;
	print = ft_realloc(print, sizeof(char)
			* (ft_strlen(print) + ft_strlen(exp) + 2));
	while (exp[i])
	{
		print[*j] = exp[i];
		i++;
		*j += 1;
	}
	i = ft_strlen(var);
	free(var);
	return (1);
}

void	echo(char *str, char **envp)
{
	int		i;
	int		j;
	char	*print;

	i = 0;
	j = 0;
	print = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		if (str[i] == '$' && str[ft_max(0, i - 1)] != '\\')
		{
			i++;
			i = varhandler(print, &j, &str[i], envp);
		}
		else
		{
			print[j] = str[i];
			i++;
			j++;
		}
	}
	print[j] = '\n';
	print[j + 1] = '\0';
	write(1, print, ft_strlen(print));
}
