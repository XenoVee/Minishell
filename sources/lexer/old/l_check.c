/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   l_check.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 21:58:29 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/23 13:12:54 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "error.h"

/*to-do: make something that makes sure
everything that leaves here is 100% A-OKAY*/

bool	check_lexer(t_data *data)
{
	t_lexer	*scan;
	if (!data->lexer)
		return (false);
	scan = data->lexer;
	if (scan->token == '|')
		return (print_error_msg("|"));
	
}