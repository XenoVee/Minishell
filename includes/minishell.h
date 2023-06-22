/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:43:14 by ohearn        #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2023/06/21 16:09:53 by rmaes         ########   odam.nl         */
=======
/*   Updated: 2023/06/22 16:37:30 by Owen          ########   odam.nl         */
>>>>>>> Owen
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "../libraries/libftprintf/libft.h"
# include "../libraries/dl_list/include/dl_list.h"
<<<<<<< HEAD
# include "../libraries/cdl_list/include/cdl_list.h"
# include "tokenizer.h"
=======
>>>>>>> Owen
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include "error.h"
# include "builtins.h"
<<<<<<< HEAD
# include "error.h"
# include "executor.h"
=======
# include "lexer.h"

/*global variable*/
//extern int		g_exit_code;
>>>>>>> Owen

/*Defines*/
# define SUCCES 0
# define FAILURE 1

/*Functions*/
<<<<<<< HEAD
int			mini_loop(void);
void		parse_input(char *string);
//bool		init_data(t_data data);
t_token		init_tkn(void);
void		check_token(char *string);
void		test(void);
void		error(char *errmsg);
=======
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

>>>>>>> Owen

/*env*/
t_cdllist	*envcpy(char **envp);
int			envsearch(t_cdllist *env, char *var);
char		*ft_getenv(t_cdllist *env, char *var);
t_cdlnode	*ft_getenvnode(t_cdllist *env, char *var);

#endif