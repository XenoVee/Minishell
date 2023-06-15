/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:43:04 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/15 16:24:47 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "tokenizer.h"
#include <stdio.h>

t_token_type	id_token(char **str)
{	
	size_t					i;
	static const t_token	comparison[] = {
	{TOKEN_IN, "<", 0}, {DOUBLE_LESSER, "<<", 0},
	{TOKEN_OUT, ">", 0}, {DOUBLE_GEATER, ">>", 0}, {TOKEN_PIPE, "|", 0},
	{S_QUOTES, "/'", 0}, {D_QUOTES, "\"", 0}, {EMPTY, NULL, 0}};

	i = 0;
	if (**str == '\0')
		return (END);
	while (comparison[i].type != EMPTY)
	{
		if ((ft_strlen(*str) >= ft_strlen(comparison[i].string))
			&& ft_strcmp(*str, comparison[i].string) == 0)
		{
			printf("Plinko\n");
			(*str) += ft_strlen(comparison[i].string);
			return (comparison[i].type);
		}
		i++;
	}
	return (TOKEN_ARG);
}

t_token	get_next_token(char **str)
{
	t_token		token;

	token.string = NULL;
	*str = split_string(*str, DELIMS);
	token.type = id_token(str);
	if (token.type == EMPTY)
		return (token);
	if (token.type == TOKEN_ARG || token.type == S_QUOTES
		|| token.type == D_QUOTES)
		token.string = assign_string(str, token.type);
	return (token);
}

t_dllist	*tokenize(char *string)
{
	t_dllist	*token_list;
	t_token		*token;
	int			leave;

	token_list = NULL;
	leave = 0;
	while (string && leave < 5)
	{
		token = malloc(sizeof(token));
		if (!token)
			exit(4);
		*token = get_next_token(&string);
		printf("The string carried in token is: %s\nIt's type is %i\n", token->string, token->type);
		dll_add_back(&token_list, dl_new_list(token));
		leave++;
		if (token->type == END)
		{
			printf("Exit condition found\n");
			break ;
		}
	}
	return (token_list);
}

void	parse_input(char *string)
{
	t_dllist	*token_list;

	token_list = tokenize(string);
	//while (token_list->current->next != NULL)
	//printf("Token type is %s\nToken content is %s\n",
	//token_list->content, token_list->content);
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