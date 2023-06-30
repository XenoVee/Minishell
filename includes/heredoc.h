/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 15:53:09 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/30 01:06:00 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# define HEREDOC_NAME "/tmp/.minishell_heredoc_"

# include "structs.h"
# include "cleanup.h"
# include <stdio.h>
# include <readline/readline.h>

void	parse_heredoc(t_data *data, t_commands **last_cmd, t_token **list);
char	*get_heredoc_name(void);
char	*get_delim_hd(char *delim, bool	*quotes);
bool	check_line_hd(t_data *data, t_data_fd *io, char **input, bool *ret);
char	*reform_string(char **words);
bool	next_char_sep(char c);
bool	var_between_quotes(char *string, int i);
char	*replace_str_hd(char *string, char *var, int index);
char	*get_val(t_data *data, t_token *temp, char *string);
bool	remove_old_ref(t_data_fd *io, bool infile);

#endif