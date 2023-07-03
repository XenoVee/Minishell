/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input_str.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 14:54:15 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:48:47 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "expander.h"
#include "parsing.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	testing_purposes(t_commands *cmd)
{
	t_commands	*test;
	int			i;

	test = cmd;
	i = 0;
	printf("testing the commands output\n");
	while (test)
	{
		if (test->cmd)
			printf("Command is %s\n", test->cmd);
		if (test->args && test->pipe == false)
		{
			printf("Args are ");
			while (test->args[i])
			{
				printf("%s ", test->args[i]);
				i++;
			}
		}
		if (test->next != NULL)
			test = test->next;
		else
			break ;
	}
	printf("\nDone with test\n");
}

bool	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	parse_input_str(t_data *data)
{
	t_token	*temp;

	if (data->user_input == NULL)
		exit(42);
	else if (ft_strcmp(data->user_input, "\0") == 0)
		return (false);
	else if (is_space(data->user_input) == true)
		return (true);
	add_history(data->user_input);
	if (tokenizer(data, data->user_input) == FAILURE)
		return (false);
	if (data->token->type == END)
		return (false);
	if (check_for_var(&data->token) == false)
		return (false);
	expand_var(data, &data->token);
	temp = data->token;
	while (temp->next != NULL)
	{
		printf("string in this one is %s\n", temp->string);
		printf("type in this one is %u\n", temp->type);
		temp = temp->next;
	}
	parse_data(data, data->token);
	testing_purposes(data->cmd);
	return (true);
}
