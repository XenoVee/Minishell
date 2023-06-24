/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input_str.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 14:54:15 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/24 11:44:24 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <readline/readline.h>
#include <readline/history.h>

static bool	is_space(char *str)
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
	if (data->user_input == NULL)
		exit(42);
	else if (ft_strcmp(data->user_input, "\0") == 0)
	{
		printf("empty string\n");
		return (false);
	}
	else if (is_space(data->user_input) == true)
	{
		printf("it's just spaces\n");
		return (true);
	}
	add_history(data->user_input);
	if (tokenizer(data, data->user_input) == FAILURE)
	{
		printf("something went wrong\n");
		return (false);
	}
	if (data->token->type == END)
		return (false);
	return (true);
}