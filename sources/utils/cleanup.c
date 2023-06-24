/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 01:20:27 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/24 14:21:28 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>

void	free_pointer(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}
}
void	free_data(t_data *data)
{
	if (data && data->user_input)
	{
		free_pointer(data->user_input);
		data->user_input = NULL;
	}
	// if (data && data->token)
	// 	/*make list clear function for token list*/
	// if (data && data->cmd)
	// 	/*make list clean function for command list*/
}

