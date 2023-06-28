/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 01:19:21 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/27 23:53:21 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include "lexer.h"

/*Functions*/
void	free_pointer(void *pointer);
void	free_data(t_data *data);
void	lst_clear_tkn(t_token **list, void (*del)(void *));
void	lst_delone_cmd(t_commands *list, void (*del)(void *));
void	lst_clear_cmd(t_commands **list, void (*del)(void *));


#endif