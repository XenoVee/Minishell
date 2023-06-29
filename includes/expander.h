/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 21:01:22 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/29 11:00:33 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <stdbool.h>
# include "structs.h"

/*Functions*/
int		expand_var(t_data *data, t_token **list);
void	replace_var(t_token **list, char *var, int index);
int		var_length(char *string);
char	*get_new_string(char *old, char *var, int len, int index);
bool	handle_quotes(t_data *data);
bool	change_status(t_token **list, int i);
void	change_status_quote(t_token **list, int *i);
bool	change_status_default(t_token **list, int *i);
void	sort_strings(t_token **list, char *new);
char	*id_variable(char *string);
bool	valid_var(t_data *data, char *var);
char	*get_value(t_data *data, t_token *temp, char *string);

#endif