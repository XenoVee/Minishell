/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cdl_nodenew.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 16:15:18 by rmaes         #+#    #+#                 */
/*   Updated: 2024/02/12 11:58:26 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>

// creates and allocates a new t_dlnode, using the given content
// the prev and next pointers are set to NULL
// On allocation failure, returns NULL
// char *n is ENV var name
// char *v is env var value
t_dlnode	*cdl_nodenew(char *n, char *v)
{
	t_dlnode	*node;

	node = malloc(sizeof(t_dlnode));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->name = n;
	node->value = v;
	return (node);
}
