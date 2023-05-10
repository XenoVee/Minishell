/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dl_create_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 16:42:39 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/09 17:31:51 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dl_list.h"

t_dllist	*dl_new_list(void)
{
	t_dllist	*list;

	list = (t_dllist *)malloc(sizeof(t_dllist));
	if (!list)
		return (NULL);
	list->content = NULL;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
