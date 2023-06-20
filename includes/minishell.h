/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:43:14 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/20 15:16:44 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "../libraries/libftprintf/libft.h"
# include "../libraries/dl_list/include/dl_list.h"
# include "tokenizer.h"
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "error.h"
# include "builtins.h"
# include "error.h"
# include "builtins.h"

/*Defines*/
# define SUCCES 0
# define FAILURE 1

/*Functions*/
int		mini_loop(void);
void	parse_input(char *string);
//bool	init_data(t_data data);
t_token	init_tkn(void);
void	check_token(char *string);
void	test(void);
void	error(char *errmsg);

/*executor*/
int			executor(char **cmd1, char **envp);
int			executort(char **cmd1, char **cmd2, char **envp);
char		*pathfinder(char *find);

/*env*/
t_dllist	*envcpy(char **envp);
int			envsearch(t_dllist *env, char *var);
char		*ft_getenv(t_dllist *env, char *var);
t_dlnode	*ft_getenvnode(t_dllist *env, char *var);

#endif