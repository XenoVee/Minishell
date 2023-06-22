/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 21:35:20 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/22 19:49:38 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

/*This needs to be reworked*/
t_token_type	id_token(char *str)
{	
	size_t					j;
	static const t_token	comparison[] = {
	{DOUBLE_LESSER, "<<", 0}, {TOKEN_IN, "<", 0}, 
	{DOUBLE_GEATER, ">>", 0}, {TOKEN_OUT, ">", 0}, {TOKEN_PIPE, "|", 0},
	{S_QUOTES, "\'", 0}, {D_QUOTES, "\"", 0}, {EMPTY, NULL, 0}};

	j = 0;
	if (*str == '\0')
		return (END);
	//printf("string length is %zu\n", ft_strlen(str));
	while (comparison[j].type != EMPTY)
	{
		if ((ft_strlen(str) >= ft_strlen(comparison[j].string))
			&& ft_strncmp(str, comparison[j].string, ft_strlen(comparison[j].string)) == 0)
		{
			//printf("The token is %s\n", comparison[j].string);
			return (comparison[j].type);
		}
		j++;
	}
	return (TOKEN_ARG);
}

int	skip_token(char *str, int i)
{
	//printf("skipping time\n");
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>' || str[i] == '|'
			|| str[i] == '\'' || str[i] == '\"' || str[i] == ' '
			|| (str[i] >= 9 && str[i] <= 13))
			return (i);
		i++;
	}
	return (i);
}

/*Initializes each part of the lexer list*/
t_lexer	*init_lexer(t_data *data, int *i, int pos)
{
	t_lexer			*new;
	int				end;

	printf("i is %i\n", *i);
	new = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new)
		exit (42);
	new->type = id_token(data->user_input + *i);
	//printf("the token is %i\n", new->type);
	new->start = *i;
	if (new->type == DOUBLE_LESSER || new->type == DOUBLE_GEATER)
		end = *i +2;
	else 
		end = skip_token(data->user_input, *i);
	new->pos = pos;
	new->content = ft_substr(data->user_input, *i, end - *i + 1);
	printf("substring is %s\n", new->content);
	new->next = NULL;
	new->prev = NULL;
	new->end = end;
	*i = end;
	//printf("i is now %i\n", *i);
	return (new);
}

static void	add_back(t_lexer *main, t_lexer *back)
{
	t_lexer	*temp;

	if (!back)
		return ;
	temp = main;
	while (temp->next)
		temp = temp->next;
	temp->next = back;
	back->prev = temp;
	return ;
}

bool	build_lexer(t_data *data)
{
	int		i;
	int		pos;
	t_lexer	*temp;

	i = 0;
	pos = 0;
	temp = NULL;
	while (data->user_input[i])
	{
		i = skip_delims(data->user_input, i);
		if (!data->user_input[i])
			break ;
		printf("I is %i\n", i);
		if (!data->lexer)
			data->lexer = init_lexer(data, &i, pos);
		else
		{
			temp = init_lexer(data, &i, pos);
			add_back(data->lexer, temp);
		}
		pos++;
		i++;
	}
	printf("test done\n");
	return (true);
}
