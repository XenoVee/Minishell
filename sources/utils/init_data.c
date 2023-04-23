/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 20:42:45 by Owen          #+#    #+#                 */
/*   Updated: 2023/04/23 14:58:06 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizer.h"

bool	init_data(t_data data)
{
	data.token = init_tkn();
	data.user_input = ft_calloc(1, sizeof(char));
	return (true);
}
