/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cdl_listaddback.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 16:17:05 by rmaes         #+#    #+#                 */
/*   Updated: 2023/04/19 15:36:11 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>

// add new node NODE to the back of LIST. If LIST is empty, it sets NODE as head
void	cdl_listaddback(t_dllist *list, t_dlnode *node)
{
	if (list->head == NULL)
	{
		list->head = node;
		list->current = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = list->head;
		node->prev = list->head->prev;
		list->head->prev->next = node;
		list->head->prev = node;
	}
	list->listlen++;
}
