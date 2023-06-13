/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:02:19 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/13 12:14:09 by rmaes         ########   odam.nl         */
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
	ret[i] = '\0';
	return (ret);
}

static int	varhandler(char **print, int *j, char *str, char **envp)
{
	char	*var;
	char	*exp;
	int		i;

	var = cutvar(str);
	exp = expand(envp, var);
	if (exp == NULL)
	{
		i = ft_strlen(var);
		free(var);
		return (i - 1);
	}
	i = 0;
	*print = ft_realloc(*print, sizeof(char)
			* (ft_strlen(*print) + ft_strlen(exp) + 1));
	while (exp[i])
	{
		print[0][*j] = exp[i];
		i++;
		*j += 1;
	}
	i = ft_strlen(var);
	free(var);
	return (i);
}

void	bi_echo(char *str, char **envp, int mode)
{
	int		i;
	int		j;
	char	*print;

	i = 0;
	j = 0;
	print = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] == '$' && mode & M_EXP)
			i += 1 + varhandler(&print, &j, &str[i + 1], envp);
		else
		{
			print[j] = str[i];
			i++;
			j++;
		}
	}
	print[j] = '\0';
	write(1, print, ft_strlen(print));
	if (!(mode & M_N))
		write(1, "\n", 1);
	free(print);
}
