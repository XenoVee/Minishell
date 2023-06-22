/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:43:04 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/21 21:47:12 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/minishell.h"
// #include "lexer.h"
// #include <stdio.h>

// t_token_type	id_token(char **str)
// {	
// 	size_t					i;
// 	static const t_token	comparison[] = {
// 	{TOKEN_IN, "<", 0}, {DOUBLE_LESSER, "<<", 0},
// 	{TOKEN_OUT, ">", 0}, {DOUBLE_GEATER, ">>", 0}, {TOKEN_PIPE, "|", 0},
// 	{S_QUOTES, "/'", 0}, {D_QUOTES, "\"", 0}, {EMPTY, NULL, 0}};

// 	i = 0;
// 	if (**str == '\0')
// 		return (END);
// 	while (comparison[i].type != EMPTY)
// 	{
// 		if ((ft_strlen(*str) >= ft_strlen(comparison[i].string))
// 			&& ft_strcmp(*str, comparison[i].string) == 0)
// 		{
// 			printf("Plinko\n");
// 			(*str) += ft_strlen(comparison[i].string);
// 			return (comparison[i].type);
// 		}
// 		i++;
// 	}
// 	return (TOKEN_ARG);
// }

// t_token	get_next_token(t_data *data, char **str)
// {
// 	t_token		token;

// 	token.string = NULL;\
// 			printf("token data is %s\nCopy string is %s\n", data->user_input, *str);
// 	//printf("status update: entered get_next_token\n");
// 	*str = split_string(*str, DELIMS);
// 	//printf("string is %s\n", *str);
// 	token.type = id_token(str);
// 	//printf("token type is %i\n", token.type);
// 	if (token.type == EMPTY)
// 		return (token);
// 	// if (token.type == TOKEN_ARG || token.type == S_QUOTES
// 	// 	|| token.type == D_QUOTES)
// 		//token.string = assign_string(str, token.type);
// 		//printf("it's a token alright\n");
// 	return (token);
// }

// t_dllist	*tokenize(t_data *data)
// {
// 	t_dllist	*token_list;
// 	t_token		*token;
// 	char		**str_cpy;
// 	int			leave;

// 	token_list = NULL;
// 	//printf("status update: entering tokenize\n");
// 	str_cpy = &data->user_input;
// 	leave = 0;
// 	while (data->user_input && leave < 5)
// 	{
// 		token = malloc(sizeof(token));
// 		if (!token)
// 			exit(4);
// 		*token = get_next_token(data, str_cpy);
// 		printf("The string carried in token is: %s\nIt's type is %i\n", token->string, token->type);
// 		dll_add_back(&token_list, dl_new_list(token));
// 		leave++;
// 		if (token->type == END)
// 		{
// 			//printf("Exit condition found\n");
// 			break ;
// 		}
// 	}
// 	return (token_list);
// }

// void	parse_input(t_data *data)
// {
// 	t_dllist	*token_list;

// 	token_list = tokenize(data);
// 	//while (token_list->current->next != NULL)
// 	printf("Token type is %s\nToken content is %s\n", (char *)token_list->content, (char *)token_list->content);
// 	return ;
// }
