/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 01:20:27 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:50:58 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include <unistd.h>
#include "readline/history.h"
#include "readline/readline.h"
#include <stdlib.h>

void	free_pointer(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}
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
				printf("freeing a word\n");
				free_pointer(arr[i]);
				arr[i] = NULL;
			}
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void	free_data_fd(t_data_fd *io)
{
	if (!io)
		return ;
	if (!io->delim_hd)
	{
		printf("removing fd\n");
		unlink(io->infile);
		free_pointer(io->delim_hd);
	}
	if (io->infile)
		free_pointer(io->infile);
	if (io->outfile)
		free_pointer(io->outfile);
	if (io)
		free_pointer(io);
}

void	free_data(t_data *data, bool clear_all)
{
	if (data && data->user_input)
	{
		printf("removing user data\n");
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
