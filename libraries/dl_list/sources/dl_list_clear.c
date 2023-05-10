/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dl_list_clear.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 15:25:30 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/10 12:31:31 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dl_list.h"

void	dll_clear(t_dllist **list, void (*del)(void *))
{
	t_dllist	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		dl_lstdelone(*list, del);
		*list = tmp;
	}
	*list = NULL;
}