/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 17:46:18 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/29 20:51:37 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structs.h"
# include <stdlib.h>
# include <fcntl.h>

# define ERR_AR	"ambiguous redirect"

void		parse_data(t_data *data, t_token *token);
t_commands	*lst_new_command(void);
void		lst_add_back_cmd(t_commands **list, t_commands *new);
t_commands	*lst_last_cmd(t_commands *list);
bool		process_args(t_token **list, t_commands *cmd);
void		parse_heredoc(t_data *data, t_commands **last_cmd, t_token **list);
void		parse_word(t_commands **cmd, t_token **list);
void		parse_input(t_commands **cmd, t_token **list);
void		parse_trunc(t_commands **cmd, t_token **list);
void		parse_append(t_commands **cmd, t_token **list);
void		parse_pipe(t_commands **cmd, t_token **list);
bool		remove_old_ref(t_data_fd *io, bool infile);

#endif