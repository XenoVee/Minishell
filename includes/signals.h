/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 14:01:38 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/25 15:25:54 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include "readline/readline.h"
# include "readline/history.h"
# include <stdio.h>
# include <unistd.h>
# include "../libraries/libftprintf/libft.h"

/*Functions*/
void		set_signals_interactive(void);
void		set_signals_noninteractive(void);

#endif