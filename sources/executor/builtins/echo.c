/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 16:02:19 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/27 16:17:54 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	bi_echo(t_commands *cmd)
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
		printf("%s", cmd->args[i - 1]);
		if (cmd->args[i])
			printf(" ");
	}
	if (newline == TRUE)
		printf("\n");
}
