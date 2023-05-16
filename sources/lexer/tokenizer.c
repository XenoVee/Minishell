/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:43:04 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/16 17:46:28 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizer.h"
#include <stdio.h>

t_token_type	id_token(char **str)
{
	
	return (NONE);
}

t_token		get_next_token(char **str)
{
	t_token		token;
	char		**ret;

	token.string = NULL;
	*str = split_string(*str, "\t\n\v\f\r");
	token.type = id_token(str);
	if (token.type == NONE)
		return (token);
	return (token);
}

t_dllist	*tokenize(char *string)
{
	t_dllist	*token_list;
	t_token		*token;

	token_list = dl_new_list();
	token = malloc(sizeof(token));
	if (!token)
		exit(-1);
	while (string)
	{
		*token = id_token(&string);
		printf("The string carried in token is: %s\n", token->string);
		// cdl_listaddback(token_list, cdl_nodenew(token->string));
		dll_add_back(token_list, dll_nodenew(token));
		// printf("Check %s\n", token_list->current->content);
	}
	return (token_list);
}

void	check_token(char *string)
{
	t_dllist	*token_list;

	token_list = tokenize(string);
	// while (token_list->current->next != NULL)
	printf("Token type is %s\nToken content is %s\n", token_list->content, token_list);
	return ;
}

// void	comment_dump_wip(void)
// {
// 	int			temp;

// 	temp = 0;
// 	if (string[i] == '<')
// 	{
// 		if (string[i + 1] == '<')
// 			printf ("Character is %c%c\n", string[i], string[i + 1]);
// 		else
// 			printf ("Character is %c\n", string[i]);
// 	}
// 	if (string[i] == '>' && string[i + 1] == '>')
// 		printf("Character is %c%c\n", string[i], string[i + 1]);
// 	if (string[i] == '\'')
// 		printf ("Character is %c\n", string[i]);
// 	if (string[i] == '\"')
// 		printf ("Character is %c\n", string[i]);
// 	if (string[i] == '|')
// 		printf ("Character is %c\n", string[i]);
// 	if (string[i] == '$')
// 		printf ("Character is %c\n", string[i]);
// }