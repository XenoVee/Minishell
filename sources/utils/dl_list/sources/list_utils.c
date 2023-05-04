/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lists.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 15:54:44 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/04 16:15:13 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "dl_list.h"

/*This is a placeholder in case I need more list related functions*/
int	list_size(t_dllist *list)
{
	int	size;

	size = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}

t_dllist	*search_last(t_dllist *list)
{
	while (list && list->next != NULL )
		list = list->next;
	return (list);
}
