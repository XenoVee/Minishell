/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 16:42:39 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/04 17:46:58 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dl_list.h"

t_dllist	dl_new_list(void *content)
{
	t_dllist	*list;

	list = (t_dllist)malloc(sizeof(t_dllist));
	if (list = NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
