/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:43:14 by ohearn        #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2023/06/15 14:41:07 by ohearn        ########   odam.nl         */
=======
/*   Updated: 2023/06/08 14:51:47 by rmaes         ########   odam.nl         */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "../libraries/libftprintf/libft.h"
# include "../libraries/dl_list/include/dl_list.h"
# include "../libraries/cdl_list/include/cdl_list.h"
<<<<<<< HEAD
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
=======
>>>>>>> master
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
void	error(char *errmsg);

/*executor*/
int		executor(char **cmd1, char **envp);
int		executort(char **cmd1, char **cmd2, char **envp);
int		executor(char **cmd1, char **envp);
int		executort(char **cmd1, char **cmd2, char **envp);
char	*pathfinder(char *find);
char	*expand(char **envp, char *var);
char	*envsearch(char **envp, char *var);
#endif