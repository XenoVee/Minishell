/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 13:54:42 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/29 17:50:32 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"

int	isint(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	bi_exit(t_commands *cmd)
{
	int	g_exit_code;

	g_exit_code = 0;
	ft_putstr_fd("exit\n", 2);
	if (cmd->args[1] == NULL)
		exit(g_exit_code % 256);
	if (!isint(cmd->args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR);
		ft_putstr_fd(cmd->args[1], STDERR);
		ft_putstr_fd(": numeric argument required\n", STDERR);
	}
	else if (cmd->args[2] != NULL)
	{
		exec_error("exit: ", "too many arguments\n");
		return ;
	}
	g_exit_code = ft_atoi(cmd->args[1]);
	exit(g_exit_code % 256);
}
