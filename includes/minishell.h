/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:43:14 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/21 16:09:53 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "../libraries/libftprintf/libft.h"
# include "../libraries/dl_list/include/dl_list.h"
# include "../libraries/cdl_list/include/cdl_list.h"
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
# include "executor.h"

/*Defines*/
# define SUCCES 0
# define FAILURE 1

/*Functions*/
int			mini_loop(void);
void		parse_input(char *string);
//bool		init_data(t_data data);
t_token		init_tkn(void);
void		check_token(char *string);
void		test(void);
void		error(char *errmsg);

/*env*/
t_cdllist	*envcpy(char **envp);
int			envsearch(t_cdllist *env, char *var);
char		*ft_getenv(t_cdllist *env, char *var);
t_cdlnode	*ft_getenvnode(t_cdllist *env, char *var);

#endif