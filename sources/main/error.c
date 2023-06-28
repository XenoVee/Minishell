/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:50:47 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/28 14:51:37 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

static bool	need_quotes(char *cmd)
{
	if (ft_strncmp(cmd, "unset", 6) == 0 || ft_strncmp(cmd, "export", 7) == 0)
		return (true);
	return (false);
}

int		cmd_err_msg(char *command, char *info, char *msg, int err)
{
	char	*err_msg;
	bool	quotes;

	quotes = need_quotes(command);
	err_msg = ft_strdup("minishell: ");
	if (command != NULL)
	{
		err_msg = ft_strjoin(err_msg, command);
		err_msg = ft_strjoin(err_msg, ": ");
	}
	if (info != NULL)
	{
		err_msg = ft_strjoin(err_msg, info);
	}
	return (err);
}

void	error(char *errmsg)
{
	ft_putstr_fd("Error\n", 2);
	if (errno == 0)
		ft_putendl_fd(errmsg, 2);
	else
		perror(errmsg);
	exit(EXIT_FAILURE);
}

bool	print_error_msg(char *str)
{
	ft_putstr_fd("minishell: syntax error near unexpected token '", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	return (false);
}
