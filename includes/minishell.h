/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:43:14 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/22 16:37:30 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "../libraries/libftprintf/libft.h"
# include "../libraries/dl_list/include/dl_list.h"
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include "error.h"
# include "builtins.h"
# include "lexer.h"

/*global variable*/
//extern int		g_exit_code;

/*Defines*/
# define SUCCES 0
# define FAILURE 1

/*Functions*/
//void	parse_input(t_data *data);
bool	init_data(t_data *data);
t_token	init_tkn(void);
//void	check_token(char *string);
//void	test(void);
//void	error(char *errmsg);
void	error(char *errmsg);
//int		env_var_count(char **env);

/*utils*/
void	null_exit(void);
void	*null_check(void *ptr);

/*string*/
char	*assign_string(char **str, t_token_type tkn);

/*enviroment*/


/*executor*/
int		executor(char **cmd1, char **envp);
int		executort(char **cmd1, char **cmd2, char **envp);
int		executor(char **cmd1, char **envp);
int		executort(char **cmd1, char **cmd2, char **envp);
char	*pathfinder(char *find);
char	*expand(char **envp, char *var);
char	*envsearch(char **envp, char *var);

#endif