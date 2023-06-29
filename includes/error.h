/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 16:46:11 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/29 17:08:04 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*includes*/
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libraries/libftprintf/libft.h"

/*Defines*/
# define ERR_MALLOC		"Malloc call failed"
# define SUCCES 0
# define FAILURE 1

/*global variable*/
extern int		g_exit_code;

/*Functions*/
void	error(char *errmsg);
bool	print_error_msg(char *str);
void	exec_error(char *cmd, char *msg);

#endif