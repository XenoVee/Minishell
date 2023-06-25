/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 21:01:22 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/25 13:58:45 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <stdbool.h>

/*Functions*/
int		expand_var(t_token **list);
void	replace_var(t_token *list, char *string, int index)

#endif