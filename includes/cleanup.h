/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 01:19:21 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/30 00:49:50 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include "lexer.h"
# include <stdio.h>

/*Functions*/
void	free_pointer(void *pointer);
void	free_data(t_data *data, bool clear_all);
void	free_str_arr(char **arr);
char	*join_str(char *str, char *add);
void	lst_clear_tkn(t_token **list, void (*del)(void *));
void	lst_delone_cmd(t_commands *list, void (*del)(void *));
void	lst_clear_cmd(t_commands **list, void (*del)(void *));


#endif