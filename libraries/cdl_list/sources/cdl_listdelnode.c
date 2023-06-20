/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cdl_listdelnode.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 17:02:37 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/19 15:02:59 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>

//deletes and frees the N'th node of LIST, and returns a pointer to the content
void	cdl_listdelnode(t_dllist *list, int n)
{
	t_dlnode	*node;

	node = cdl_listpopnode(list, n);
	free (node->name);
	free (node->value);
	free(node);
}
