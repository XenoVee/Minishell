/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dl_list.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 16:08:52 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/04 16:15:38 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DL_LIST_H
# define DL_LIST_H

# include <stddef.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_dllist
{
	void			*content;
	struct s_dllist	*next;
	struct s_dllist	*prev;
}				t_dllist;

#endif
