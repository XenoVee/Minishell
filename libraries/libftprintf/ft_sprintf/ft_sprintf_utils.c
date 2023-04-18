/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprintf_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/28 14:47:15 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/12 16:53:21 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"
#include <stdlib.h>

int	ft_partlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '%' && s[a])
		a++;
	return (a);
}

//returns a malloced string that is the result of appending str2 to str1.
// frees str1
char	*ft_realc_strjoin(char *str1, char *str2)
{
	char	*ret;

	ret = ft_strjoin(str1, str2);
	free(str1);
	return (ret);
}
