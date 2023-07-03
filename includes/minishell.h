/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:43:14 by ohearn        #+#    #+#                 */
/*   Updated: 2023/07/03 16:22:02 by rmaes         ########   odam.nl         */
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
# include "structs.h"
# include "error.h"
# include "builtins.h"
# include "executor.h"
# include "lexer.h"

/*Functions*/
void		exit_ms(t_data *data, int num);
t_token		init_tkn(void);
void		check_token(char *string);
bool		init_data(t_data *data, char **env);
void		error(char *errmsg);

/*utils*/
void		null_exit(void);
void		*null_check(void *ptr);

/*string*/
//char	*assign_string(char **str, t_token_type tkn);

/*enviroment*/

/*env*/

#endif