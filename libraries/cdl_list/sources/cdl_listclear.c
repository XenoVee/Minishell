/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cdl_listclear.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 18:03:54 by rmaes         #+#    #+#                 */
/*   Updated: 2023/04/19 15:33:45 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>

// deletes and frees all nodes, and the list itself
void	cdl_listclear(t_dllist *list)
{
	while (list->head)
		cdl_listdelnode(list, 0);
	free(list);
}
