/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_listincr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 16:19:07 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/15 16:15:58 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cdl_list.h"
#include <stdlib.h>

// Shift up all elements of LIST by 1.
// The first element becomes the last one.
void	cdl_listincr(t_dllist *list)
{
	list->head = list->head->next;
}
