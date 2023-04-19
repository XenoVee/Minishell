/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cdl_listaddfront.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 16:16:44 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/15 16:25:05 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>

// add new node NODE to the front of LIST, and sets it as head
void	cdl_listaddfront(t_dllist *list, t_dlnode *node)
{
	cdl_listaddback(list, node);
	cdl_listdecr(list);
}
