/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   n_tokenizer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 18:15:15 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/19 20:23:46 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "tokenizer.h"

/*trying a different approach*/

int	save_status(int status, char *str, int i)
{
	if (str[i] == '\'' && status == DEFAULT)
		status = S_Q;
	else if (str[i] == '\"' && status == DEFAULT)
		status = D_Q;
	else if (str[i] == '\'' && status == S_Q)
		status = DEFAULT;
	else if (str[i] == '\"' && status == D_Q)
		status == DEFAULT;
	return (status);  
}

int	tokenization(t_data *data, char *str)
{
	int	i;
	int	start;
	int	end;
	int	status;

	i = -1;
	start = 0;
	end = ft_strlen(str);
	status = DEFAULT;
	while (i++ <= end)
	{
		status = set_status(status, str, i);
		if (status == DEFAULT)
			start = save_part(&i, str, data, start);
	}
	return (0);
}