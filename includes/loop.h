/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 15:51:28 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/23 11:13:29 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "lexer.h"

/*Functions*/
int		mini_loop(t_data *data);
//int		mini_loop(void);

#endif