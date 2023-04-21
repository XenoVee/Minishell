/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:43:04 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/21 12:37:58 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizer.h"
#include <stdio.h>

t_token	id_token(char **str)
{
	t_token		token;

	token = init_tkn();
	token.string = *str;
	printf ("does it work? %s\n", token.string);
	return (token);
}

t_dllist	*tokenize(char *string)
{
	t_dllist	*token_list;
	t_token		*token;

	token_list = cdl_listinit();
	token = malloc(sizeof(token));
	if (!token)
	{
		printf ("error found\n");
		exit(-1);
	}
	while (string)
	{
		*token = id_token(&string);
		printf ("p.1\n");
		cdl_listaddback(token_list, cdl_nodenew(token));
		printf ("p.6\n");
		string++;
	}
	return (token_list);
}

void	check_token(char *string, int i)
{
	t_dllist	*token_list;

	if (string[i] == '<')
	{
		if (string[i + 1] == '<')
			printf ("Character is %c%c\n", string[i], string[i + 1]);
		else
			printf ("Character is %c\n", string[i]);
	}
	if (string[i] == '>' && string[i + 1] == '>')
		printf("Character is %c%c\n", string[i], string[i + 1]);
	if (string[i] == '\'')
		printf ("Character is %c\n", string[i]);
	if (string[i] == '"')
		printf ("Character is %c\n", string[i]);
	if (string[i] == '|')
		printf ("Character is %c\n", string[i]);
	if (string[i] == '$')
		printf ("Character is %c\n", string[i]);
	token_list = tokenize(string);
	return ;
}
