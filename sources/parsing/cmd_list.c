/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_list.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 18:14:13 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/29 12:06:43 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cleanup.h"

t_commands	*lst_new_command(void)
{
	t_commands	*new;

	new = (t_commands *)malloc(sizeof(t_commands));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_commands));
	new->cmd = NULL;
	new->args = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lst_add_back_cmd(t_commands **list, t_commands *new)
{
	t_commands	*start;

	start = *list;
	if (!start)
	{
		start = new;
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
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	lst_delone_cmd(t_commands *list, void (*del)(void *))
{
	if (list->args)
		free_string_array(list->args);
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


