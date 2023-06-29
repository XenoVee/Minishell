/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:02:19 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/29 17:11:57 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	bi_echo(t_commands *cmd, int fd)
{
	int	i;
	int	j;
	int	newline;

	newline = TRUE;
	i = 1;
	while (cmd->args[i] && cmd->args[i][0] == '-')
	{
		j = 1;
		while (cmd->args[i][j] == 'n')
			j++;
		if (!cmd->args[i][j])
			newline = FALSE;
		else
			break ;
		i++;
	}
	while (cmd->args[i] && cmd->args[i++])
	{
		ft_putstr_fd(cmd->args[i - 1], fd);
		if (cmd->args[i])
			write(1, " ", 1);
	}
	if (newline == TRUE)
		write(1, "\n", 1);
}
