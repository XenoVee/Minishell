/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_list.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 18:14:13 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:50:31 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cleanup.h"

t_commands	*lst_new_command(bool pipe)
{
	t_commands	*new;

	new = (t_commands *)malloc(sizeof(t_commands));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_commands));
	new->pipe = pipe;
	init_cmd(&new);
	return (new);
}

void	lst_add_back_cmd(t_commands **list, t_commands *new)
{
	t_commands	*start;

	start = *list;
	if (!start)
	{
		*list = new;
		return ;
	}
	if (list && *list && new)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new;
		new->prev = start;
	}
}

t_commands	*lst_last_cmd(t_commands *list)
{
	while (list && list->next != NULL)
		list = list->next;
	return (list);
}

void	lst_delone_cmd(t_commands *list, void (*del)(void *))
{
	if (list->cmd)
		(*del)(list->cmd);
	if (list->args)
		free_str_arr(list->args);
	if (list->fd_data)
		free_data_fd(list->fd_data);
	(*del)(list);
}

void	lst_clear_cmd(t_commands **list, void (*del)(void *))
{
	t_commands	*temp;

	temp = NULL;
	while (*list != NULL)
	{
		temp = (*list)->next;
		lst_delone_cmd(*list, del);
		*list = temp;
	}
}
