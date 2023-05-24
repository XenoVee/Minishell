/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   minishell.h										:+:	:+:			*/
/*													 +:+					*/
/*   By: ohearn <ohearn@student.codam.nl>			 +#+					 */
/*												   +#+					  */
/*   Created: 2023/04/18 17:43:14 by ohearn		#+#	#+#				 */
/*   Updated: 2023/04/19 20:37:54 by Owen		  ########   odam.nl		 */
/*																			*/
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

/*Defines*/
# define SUCCES 0
# define FAILURE 1

/*Functions*/
int		mini_loop(void);
void	parse_input(char *string);
//bool	init_data(t_data data);
t_token	init_tkn(void);

#endif