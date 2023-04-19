/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:43:04 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/19 17:38:00 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizer.h"

// int		create_token(char *string, char split)
// {
// }
void	check_token(char *string)
{
	int	i;

	while (string[i])
	{
		if (string[i] == '<')
		{
			if (string[i + 1] == '<')
			{
				printf ("Character is %c%c\n", string[i], string[i + 1]);
				i++;
			}
			else
				printf ("Character is %c\n", string[i]);
		}
		else if (string[i] == "'")
			printf ("Character is %c\n", string[i]);
		else if (string[i] == '"')
			printf ("Character is %c\n", string[i]);
		i++;
	}
	return (0);
}
