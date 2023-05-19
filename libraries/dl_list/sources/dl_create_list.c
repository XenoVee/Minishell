/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dl_create_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 16:42:39 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/19 17:55:51 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dl_list.h"

t_dllist	*dl_new_list(void *content)
{
	t_dllist	*list;

	list = (t_dllist *)malloc(sizeof(t_dllist));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
