/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 09:56:49 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/19 14:57:57 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libraries/dl_list/include/dl_list.h"
# include "tokenizer.h"

/*Structs (added to tokenizer)*/
typedef struct s_commands
{
	t_dllist	*args;
	t_dllist	*outf;
	t_dllist	*inf;
}		t_commands;

typedef struct s_token
{
	t_token_type	type;
	char			*string;
	int				status;
}		t_token;

typedef struct s_data
{
	t_token	token;
	char	*user_input;
}		t_data;

#endif