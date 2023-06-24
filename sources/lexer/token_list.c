/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 20:07:18 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/24 13:09:20 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "cleanup.h"

t_token	*new_token(char *str, char *str_cpy, int type, int status)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token) * 1);
	if (!new_node)
		return (NULL);
	new_node->type = type;
	new_node->string = str;
	new_node->string_cpy = str_cpy;
	new_node->var = false;
	new_node->status = status;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	lst_add_back_tkn(t_token **lst, t_token *new)
{
	t_token	*start;

	start = *lst;
	if (!start)
	{
		*lst = new;
		return ;
	}
	if (lst && *lst && new)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new;
		new->prev = start;
	}
}

void	lst_delone_tkn(t_token *lst, void (*del)(void *))
{
	if (del && lst && lst->string)
	{
		(*del)(lst->string);
		lst->string = NULL;
	}
	if (del && lst && lst->string_cpy)
	{
		(*del)(lst->string_cpy);
		lst->string_cpy = NULL;
	}
	if (lst->next)
		lst->next->prev = lst->prev;
	if (lst->prev)
		lst->prev->next = lst->next;
	free_pointer(lst);
}

