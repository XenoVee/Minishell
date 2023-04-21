/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cdl_nodenew.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 16:15:18 by rmaes         #+#    #+#                 */
/*   Updated: 2023/04/21 11:41:11 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>
#include <stdio.h>

// creates and allocates a new t_dlnode, using the given content
// the prev and next pointers are set to NULL
// On allocation failure, returns NULL
t_dlnode	*cdl_nodenew(void *content)
{
	t_dlnode	*node;

	printf ("p.2\n");
	node = malloc(sizeof(t_dlnode));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->content = content;
	printf ("p.3\n");
	return (node);
}
