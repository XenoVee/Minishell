/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_create_echo.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/30 08:44:51 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/30 16:48:30 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cleanup.h"

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

int	count_e_args(t_token *list)
{
	int	i;

	i = 0;
	while (list && (list->type == WORD || list->type == VAR))
	{
		if (list->type == VAR && list->join == true)
		{
			while (list->type == VAR && list->join == true)
				list = list->next;
			i++;
		}
		else
		{
			i++;
			list = list->next;
		}
	}
	return (i);
}

void	remove_empty_vars(t_token **list)
{
	t_token	*temp;

	temp = *list;
	while (temp->type == WORD || temp->type == VAR)
	{
		if (temp->type == VAR && temp->string[0] == '\0'
			&& temp->valid_var == false)
		{
			temp = temp->next;
			if (temp == (*list)->next)
				(*list) = (*list)->next;
			lst_delone_tkn(temp->prev, free_pointer);
		}
		else
			temp = temp->next;
	}
}

char	*merge_vars(t_token **list)
{
	char	*string;
	t_token	*temp;

	temp = *list;
	string = ft_strdup(temp->string);
	while ((temp->type == VAR && temp->next->type == VAR)
			|| temp->join == true)
	{
		string = join_str(string, temp->next->string);
		temp = temp->next;
	}
	(*list) = temp;
	return (string);
}

int	create_args_ecmd(t_token **list, t_commands *cmd)
{
	t_token	*temp;
	int		count;
	int		i;

	i = 1;
	remove_empty_vars(list);
	temp = *list;
	count = count_e_args(temp);
	cmd->args = malloc(sizeof(char *) * (count + 2));
	if (!cmd->args)
		return (1);
	cmd->args[0] = ft_strdup(cmd->cmd);
	while (temp->type == WORD || temp->type == VAR)
	{
		if (temp->join == true)
			cmd->args[i] = merge_vars(&temp);
		else
			cmd->args[i] = ft_strdup(temp->string);
		i++;
		temp = temp->next;
	}
	cmd->args[i] = "\0";
	(*list) = temp;
	return (0);
}