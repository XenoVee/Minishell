/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:43:04 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/20 09:21:19 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizer.h"
#include <stdio.h>
// int		create_token(char *string, char split)
// {
// }
void	check_token(char *string, int i)
{
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
	return ;
}
