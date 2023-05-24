/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 17:07:38 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/24 18:00:59 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*string related functions*/
// int		is_delim(char c)
// {
// 	if ((c >= 9 && c <= 13) || c == 32 || c == 0)
// 		return (1);
// 	return (0);
// }

char	*find_char(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			printf("Bingo\n");
			return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}

char	*split_string(const char *str, const char *delims)
{
	while (*str != '\0' && find_char(delims, *str))
	{
		printf("Does it loop?\n");
		str++;
	}
	return ((char *)str);
}

char	*assign_string(char **str, t_token_type tkn)
{
	char	*leftover;
	//char	

	leftover = str - 1;
	while (leftover--)
	{
		
	}
}
