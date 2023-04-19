/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:44:45 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/19 17:26:35 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

/*Structs*/
// typedef enum identifier
// {
// }

typedef struct s_token
{
	int		type;
	char	**string;
}		t_token;

/*Functions*/

#endif