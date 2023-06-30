/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_list_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 16:53:36 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/30 16:58:13 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_cmd(t_commands **cmd)
{
	(*cmd)->cmd = NULL;
	(*cmd)->args = NULL;
	(*cmd)->next = NULL;
	(*cmd)->prev = NULL;
}
