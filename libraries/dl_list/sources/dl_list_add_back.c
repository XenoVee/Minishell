/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dl_list_add_back.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 17:45:54 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/10 12:54:02 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dl_list.h"

void	dll_add_back(t_dllist	*list, t_dllist *new)
{
	t_dllist	*tail;

	if (!list || !new)
		return ;
	if (list->content == NULL)
		list->content = new->content;
	else
	{
		tail = search_last(list);
		tail->next = new;
		new->prev = tail;
	}
}
