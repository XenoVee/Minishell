/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listdecr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 16:19:07 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/15 16:16:09 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>

// Shift down all elements of LIST by 1.
// The last element becomes the first one.
void	cdl_listdecr(t_dllist *list)
{
	list->head = list->head->prev;
}
