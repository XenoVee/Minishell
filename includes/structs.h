/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 09:56:49 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/21 10:30:51 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libraries/cdl_list/include/cdl_list.h"

/*Structs*/
typedef struct s_commands
{
	t_dllist	*args;
	t_dllist	*outf;
	t_dllist	*inf;
}		t_commands;

typedef struct s_token
{
	int		type;
	int		status;
	char	*string;

}		t_token;

typedef struct s_data
{
	t_token	token;
}		t_data;

#endif