/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pathfinder.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 18:50:31 by rmaes         #+#    #+#                 */
/*   Updated: 2023/05/05 14:46:09 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

char	*pathfinder(char *find)
{
	char	*path;
	char	**split;
	int		i;
	char	*check;

	path = getenv("PATH");
	split = ft_split(path, ':');
	find = ft_strjoin("/", find);
	i = 0;
	while (split[i])
	{
		check = ft_strjoin(split[i], find);
		if (access(check, F_OK) == 0)
		{
			free (find);
			return (check);
		}
		free(check);
		i++;
	}
	perror("minishell");
	exit(1);
}
