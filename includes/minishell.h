/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   minishell.h										:+:	:+:			*/
/*													 +:+					*/
/*   By: ohearn <ohearn@student.codam.nl>			 +#+					 */
/*												   +#+					  */
/*   Created: 2023/04/18 17:43:14 by ohearn		#+#	#+#				 */
/*   Updated: 2023/04/19 20:37:54 by Owen		  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "../libraries/libftprintf/libft.h"
# include "../libraries/cdl_list/include/cdl_list.h"
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>

/*Defines*/
# define SUCCES 0
# define FAILURE 1

/*Structs*/
typedef struct s_token
{
	int		type;
	int		status;
	char	*string;
	bool	exists;

}		t_token;

typedef struct s_data
{
	t_token token;
}		t_data;

/*Functions*/
void	check_token(char *string, int i);
bool	init_data(t_data *data);
t_token	init_tkn(t_token new);

#endif