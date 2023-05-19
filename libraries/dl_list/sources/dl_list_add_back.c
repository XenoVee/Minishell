/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dl_list_add_back.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 17:45:54 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/19 17:53:00 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dl_list.h"

void	dll_add_back(t_dllist **list, t_dllist *new)
{
	t_dllist	*tail;

	if (!list || !new)
		return ;
	//printf("Checkpoint reached in add_back\n");
	tail = search_last(*list);
	//printf("Checkpoint post search_last\n");
	if (tail != NULL)
		tail->next = new;
	else
		*list = new;
	//printf("Checkpoint post tail->next = new\n");
	//new->prev = tail;
	//printf("Checkpoint end of add_back\n");
}
