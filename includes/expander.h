/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 21:01:22 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/26 14:14:41 by Owen          ########   odam.nl         */
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
char	*get_new_string(char *old, char *new, int len, int index);

#endif