/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:43:14 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/24 13:33:22 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "../libraries/libftprintf/libft.h"
# include "../libraries/cdl_list/include/cdl_list.h"
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include "error.h"
# include "builtins.h"
# include "error.h"
# include "executor.h"
# include "lexer.h"

/*global variable*/
//extern int		g_exit_code;

/*Functions*/
void		exit_ms(t_data *data, int num);
t_token		init_tkn(void);
void		check_token(char *string);
bool		init_data(t_data *data, char **env);
void		error(char *errmsg);

/*utils*/
void	null_exit(void);
void	*null_check(void *ptr);

/*string*/
//char	*assign_string(char **str, t_token_type tkn);

/*enviroment*/

/*env*/
t_dllist	*envcpy(char **envp);
int			envsearch(t_dllist *env, char *var);
char		*ft_getenv(t_dllist *env, char *var);
t_dlnode	*ft_getenvnode(t_dllist *env, char *var);

#endif