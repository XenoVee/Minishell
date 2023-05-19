/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 17:07:38 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/19 16:50:58 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*string related functions*/
int		is_delim(char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

char	*find_char(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*split_string(char *str, char *delims)
{
	while (*str && find_char(delims, *str) != NULL)
		str++;
	return ((char *)str);
}
