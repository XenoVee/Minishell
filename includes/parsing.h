/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 17:46:18 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/29 14:43:07 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structs.h"
# include <fcntl.h>

void		parse_data(t_data *data, t_token *token);
t_commands	*lst_new_command(void);
void		lst_add_back_cmd(t_commands **list, t_commands *new);
t_commands	*lst_last_cmd(t_commands *list);
bool		process_args(t_token **list, t_commands *cmd);

#endif