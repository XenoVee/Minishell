/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_args.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 11:33:15 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:50:45 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cleanup.h"

int	count_args(t_token *list)
{
	int	i;

	i = 0;
	printf("entering counter\n");
	while (list && (list->type == WORD || list->type == VAR))
	{
		i++;
		list = list->next;
	}
	return (i);
}

char	**merge_strings(char **words, t_commands *cmd, t_token **list, int size)
{
	int		i;
	t_token	*temp;

	i = 0;
	printf("merging strings\n");
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
	words[i] = "\0";
	return (words);
}

bool	add_args_cmd(t_token **list, t_commands *cmd)
{
	int		i;
	int		size;
	char	**words;
	t_token	*temp;

	printf("adding args\n");
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
		return (1);
	words = merge_strings(words, cmd, list, size);
	printf("words got filled correctly\n");
	free(cmd->args);
	cmd->args = words;
	free_str_arr(words);
	return (0);
}

bool	create_args_cmd(t_token **list, t_commands *cmd)
{
	int		i;
	int		size;
	t_token	*temp;

	i = 0;
	printf("creating args\n");
	temp = *list;
	size = count_args(*list);
	printf("size is configured\n");
	cmd->args = (char **)malloc(sizeof(char *) * (size + 2));
	if (!cmd->args)
		return (1);
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
	return (0);
}

bool	process_args(t_token **list, t_commands *cmd)
{
	if (!ft_strcmp(cmd->cmd, "echo"))
	{
		printf("echo found\n");
		if (!cmd->args)
			return (create_args_ecmd(list, cmd));
		else
			return (add_args_ecmd(list, cmd));
	}
	else
	{
		printf("no echo\n");
		if (cmd && !(cmd->args))
			return (create_args_cmd(list, cmd));
		else
			return (add_args_cmd(list, cmd));
	}
	return (true);
}
