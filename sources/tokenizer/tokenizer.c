/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:43:04 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/19 15:07:43 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizer.h"

int		create_token(char *string, char split, char **output)
{
	
}

void	check_token(char *string)
{
	int	i;

	while (string[i])
	{
		if (string[i] == '"')
			create_token(string, '"', );
	}
}
