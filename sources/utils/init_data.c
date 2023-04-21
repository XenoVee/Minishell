/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 20:42:45 by Owen          #+#    #+#                 */
/*   Updated: 2023/04/20 09:26:42 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizer.h"

bool	init_data(t_data *data)
{
	data->token = init_tkn();
	return (true);
}