/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:44:45 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/19 19:12:24 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

/*Structs*/
typedef enum id
{
	LESSER = 1,
	DOUBLE_LESSER = 2,
	GREATER = 3,
	DOUBLE_GEATER = 4,
	S_QUOTES = 5,
	D_QUOTES = 6,
	PIPE = 7,
	DOLLARSGN = 8,
}		t_id;

typedef struct s_token
{
	int		type;
	char	**string;
}		t_token;

/*Functions*/

#endif