/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:43:14 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/08 15:37:18 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "../libraries/libftprintf/libft.h"
# include "../libraries/cdl_list/include/cdl_list.h"
# include "error.h"
# include "builtins.h"

/*Defines*/

/*Structs*/

/*Functions*/
void	check_token(char *string);
void	test(void);
void	error(char *errmsg);

/*executor*/
int		executor(char **cmd1, char **envp);
int		executort(char **cmd1, char **cmd2, char **envp);
char	*pathfinder(char *find);
char	*expand(char **envp, char *var);
int		envsearch(char **envp, char *var);
#endif