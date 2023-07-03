/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 13:37:00 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:47:58 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "cleanup.h"

/*Exits the shell and frees the data struct*/
void	exit_ms(t_data *data, int num)
{
	if (data)
	{
		free_data(data, false);
	}
	exit(num);
}
