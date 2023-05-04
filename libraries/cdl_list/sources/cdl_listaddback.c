/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cdl_listaddback.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 16:17:05 by rmaes         #+#    #+#                 */
/*   Updated: 2023/05/04 15:54:28 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>
#include <stdio.h>

// add new node NODE to the back of LIST. If LIST is empty, it sets NODE as head
void	cdl_listaddback(t_dllist *list, t_dlnode *node)
{
	if (list == NULL || node == NULL)
	{
		printf ("Gotcha\n");
		exit(1);
	}
	if (list->head == NULL)
	{
		printf ("p.4-1\n");
		list->head = node;
		list->current = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		printf ("p.4-2\n");
		node->next = NULL;
		node->prev = list->head->prev;
		list->head->prev->next = node;
		list->head->prev = node;
	}
	list->listlen++;
}
