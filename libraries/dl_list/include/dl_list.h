/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dl_list.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 16:08:52 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/10 12:51:29 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DL_LIST_H
# define DL_LIST_H

# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_dllist
{
	void			*content;
	struct s_dllist	*next;
	struct s_dllist	*prev;
}				t_dllist;

typedef struct s_dllnode
{
	struct s_dllnode	*prev;
	char			*content;
	struct s_dllnode	*next;
}				t_dllnode;

/*functions*/

t_dllist	*dl_new_list(void);
t_dllist	*search_last(t_dllist *list);
t_dllist	*dll_nodenew(char *string);
void		dl_ndel(void *content);
void		dll_add_back(t_dllist	*list, t_dllist *new);
void		dl_lstdelone(t_dllist *list, void (*del)(void *));
void		dll_clear(t_dllist **list, void (*del)(void *));
void		dl_lstiter(t_dllist *list, void (*f)(void *));
int			list_size(t_dllist *list);

#endif
