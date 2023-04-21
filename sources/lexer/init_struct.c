/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 15:06:11 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/21 11:33:19 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizer.h"

t_token	init_tkn(void)
{
	t_token	new;

	new.type = 0;
	new.status = 0;
	new.string = NULL;
	return (new);
}
