/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_iter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 15:48:34 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/09 15:49:03 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dl_list.h"

void	ft_lstiter(t_dllist *list, void (*f)(void *))
{
	if (!list || !f)
		return ;
	while (list)
	{
		f(list->content);
		list = list->next;
	}
}
