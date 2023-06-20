/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dl_create_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 17:02:37 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/20 15:17:52 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>

//deletes and frees the N'th node of LIST, and returns a pointer to the content
void	*cdl_listdelnode(t_dllist *list, int n)
{
	t_dlnode	*node;
	void		*content;

	node = cdl_listpopnode(list, n);
	content = node->content;
	free(node);
	return (content);
}
