/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 01:20:27 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/30 00:33:20 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "lexer.h"
#include "readline/history.h"
#include "readline/readline.h"
#include <stdio.h>
#include <stdlib.h>

void	free_pointer(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}
}

char	*join_str(char *str, char *add)
{
	char	*tmp;

	if (!add)
		return (str);
	if (!str)
		return (ft_strdup(add));
	tmp = str;
	str = ft_strjoin(tmp, add);
	free_pointer(tmp);
	return (str);
}

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			if (arr[i])
			{
				free_pointer(arr[i]);
				arr[i] = NULL;
			}
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void	free_data(t_data *data, bool clear_all)
{
	if (data && data->user_input)
	{
		free_pointer(data->user_input);
		data->user_input = NULL;
	}
	if (data && data->token)
		lst_clear_tkn(&data->token, &free_pointer);
	if (data && data->cmd)
		lst_clear_cmd(&data->cmd, &free_pointer);
	if (clear_all == true)
	{
		cdl_listclear(data->env);
		rl_clear_history();
	}
}
