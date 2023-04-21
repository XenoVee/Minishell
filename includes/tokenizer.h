/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:44:45 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/21 10:49:19 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

/*Structs*/
typedef enum e_id
{
	LESSER = 1,
	DOUBLE_LESSER = 2,
	GREATER = 3,
	DOUBLE_GEATER = 4,
	S_QUOTES = 5,
	D_QUOTES = 6,
	PIPE = 7,
	DOLLARSGN = 8
}	t_id;

typedef enum e_token_type
{
	TOKEN_ARG,
	TOKEN_NOEX,
	TOKEN_OUT,
	TOKEN_IN,
	TOKEN_PIPE
}	t_token_type;

#endif