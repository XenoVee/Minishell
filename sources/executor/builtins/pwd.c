/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:11:01 by rmaes         #+#    #+#                 */
/*   Updated: 2023/07/03 16:53:20 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <libc.h>

void	bi_pwd(int fd)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, fd);
	write(fd, "\n", 1);
	free (path);
}
