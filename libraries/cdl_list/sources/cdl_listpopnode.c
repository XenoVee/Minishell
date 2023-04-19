/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cdl_listpopnode.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 16:44:30 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/15 16:22:21 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>

// takes the N'th node from LIST, (head is node 0) and removes it from the list.
// returns a pointer to the removed node
t_dlnode	*cdl_listpopnode(t_dllist *list, int n)
{
	t_dlnode	*node;

	node = cdl_listgetnode(list, n);
	if (node == NULL)
		return (NULL);
	node->next->prev = node->prev;
	node->prev->next = node->next;
	if (node == list->head)
	{
		if (node == node->next)
			list->head = NULL;
		else
			list->head = node->next;
	}
	node->next = NULL;
	node->prev = NULL;
	list->listlen--;
	return (node);
}
