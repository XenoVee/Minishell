/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 15:39:36 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/30 15:28:16 by rmaes         ########   odam.nl         */
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
enum e_fildes
{
	STDIN = 0,
	STDOUT,
	STDERR,
};

/*Functions*/
int		executor(t_commands *cmd, t_dllist *env);
char	*pathfinder(char *find);
char	**arrayize(t_dllist *env);
size_t	safestrlen(char *s);
void	endpipe(t_commands *cmd, int *pipenew, int *pipeold);
void	startpipe(t_commands *cmd, int *pipenew, int *pipeold);

#endif