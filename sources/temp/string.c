/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 17:07:38 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/21 14:28:58 by Owen          ########   odam.nl         */
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
		//printf("does it enter tho?\n");
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	//printf("Character was %c\n", c);
	return (NULL);
}
/*Returns a pointer to the next word*/
char	*split_string(const char *str, const char *delims)
{
	//printf("string is %s\n", str);
	//printf("status update: entered split_string\n");
	while (*str != '\0' && find_char(delims, *str) == NULL)
		str++;
	return ((char *)str);
}

char	*assign_string(char **str, t_token_type tkn)
{
	char	*leftover;

	(void)tkn;
	leftover = *str - 1;
	printf("test: Original string is %s\nThe new string is %s\n", *str, leftover);
	// while (leftover++)
	// {
	// 	if (*leftover == '\0')
	// }
	return (NULL);
}
