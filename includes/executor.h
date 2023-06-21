/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 15:39:36 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/21 16:08:42 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

/*Defines*/
enum e_strlens
{
	NAME=0,
	VALUE,
};

/*Functions*/
int		executor(char **cmd1, t_dllist *env);
char	*pathfinder(char *find);
char	**arrayize(t_dllist *env);

#endif