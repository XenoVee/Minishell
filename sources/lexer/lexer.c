/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 21:35:20 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/22 16:32:21 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

/*This needs to be reworked*/
t_token_type	id_token(char *str)
{	
	size_t					j;
	static const t_token	comparison[] = {
	{TOKEN_IN, "<", 0}, {DOUBLE_LESSER, "<<", 0},
	{TOKEN_OUT, ">", 0}, {DOUBLE_GEATER, ">>", 0}, {TOKEN_PIPE, "|", 0},
	{S_QUOTES, "\'", 0}, {D_QUOTES, "\"", 0}, {EMPTY, NULL, 0}};

	j = 0;
	if (*str == '\0')
		return (END);
	while (comparison[j].type != EMPTY)
	{
		if ((ft_strlen(str) >= ft_strlen(comparison[j].string))
			&& ft_strncmp(str, comparison[j].string, ft_strlen(comparison[j].string)) == 0)
			return (comparison[j].type);
		j++;
	}
	return (TOKEN_ARG);
}

int	skip_token(char *str, int i)
{
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

	new = (t_lexer *)malloc(sizeof(t_lexer));
	if (!new)
		exit (42);
	new->type = id_token(&data->user_input);
	new->start = i;
	if (new->type == DOUBLE_LESSER || new->type == DOUBLE_GEATER)
		end = i +1;
	else 
		end = skip_token(data->user_input, *i);
	new->pos = *i;
	new->content = ft_substr(data->user_input, i, end - *i);
	new->next = NULL;
	new->prev == NULL;
	new->end = end;
	return (new);
}

static void	add_back(t_lexer *main, t_lexer *back)
{
	
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
		i += skip_delims(data->user_input);
		if (!data->lexer)
		{
			data->lexer = init_lexer(data, &i, pos);
		}
		if (!data->lexer)
			return (false);
		else
		{
			temp = init_lexer(data, &i, pos);
			add_back(data->lexer, temp);
		}
		pos++;
		i++;
	}
	return (true);
}
