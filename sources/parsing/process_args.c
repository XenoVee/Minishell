/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_args.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 11:33:15 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/29 15:00:46 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cleanup.h"

int	count_args(t_token *list)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->type == WORD || list->type == VAR)
		{
			i++;
			list = list->next;
		}
	}
	return (i);
}

char	**merge_strings(char **words, t_commands *cmd, t_token **list, int size)
{
	int		i;
	t_token	*temp;

	i = 0;
	temp = *list;
	while (i < size)
	{
		words[i] = cmd->args[i];
		i++;
	}
	while (temp->type == WORD || temp->type == VAR)
	{
		words[i] = ft_strdup(temp->string);
		i++;
		temp = temp->next;
	}
	words[i] = '\0';
	return (words);
}

bool	add_args_cmd(t_token **list, t_commands *cmd)
{
	int		i;
	int		size;
	char	**words;
	t_token	*temp;

	i = 0;
	size = 0;
	temp = *list;
	while (temp->type == WORD || temp->type == VAR)
	{
		i++;
		temp = temp->next;
	}
	while (cmd->args[size])
		size++;
	words = (char **)malloc(sizeof(char *) * (i + size + 1));
	if (!words)
		return (false);
	words = merge_strings(words, cmd, list, size);
	free(cmd->args);
	cmd->args = words;
	free_str_arr(words);
	return (true);
}

bool	create_args_cmd(t_token **list, t_commands *cmd)
{
	int		i;
	int		size;
	t_token	*temp;

	i = 0;
	size = count_args(list) + 2;
	temp = *list;
	cmd->args = (char **)malloc(sizeof(char *) * size);
	if (!cmd->args)
		return (false);
	temp = *list;
	cmd->args[i] = ft_strdup(cmd->cmd);
	i++;
	while (temp->type == WORD || temp->type == VAR)
	{
		cmd->args[i] = ft_strdup(temp->string);
		i++;
		temp = temp->next;
	}
	cmd->args[i] = NULL;
	*list = temp;
	return (true);
}

bool	process_args(t_token **list, t_commands *cmd)
{
	if (!ft_strcmp(cmd->args[0], "echo"))
	{
		/*echo stuff, I do later if needed. Zach said no*/
	}
	else
	{
		if (cmd && !(cmd->args[1]))
			return (create_args_cmd(list, cmd));
		else
			return (add_args_cmd(list, cmd));
	}
	return (true);
}
