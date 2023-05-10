/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dl_newnode.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/09 16:19:37 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/09 17:20:16 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dl_list.h"

t_dllist	*dll_nodenew(char *string)
{
	t_dllist	*node;

	node = dl_new_list();
	node->content = string;
	return (node);
}