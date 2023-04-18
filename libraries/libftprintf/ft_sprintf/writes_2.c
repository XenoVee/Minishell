/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writes_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 17:04:38 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/12 17:30:37 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_join_ptr(unsigned long x, char *str, int i)
{
	if (x >= 16)
	{
		ft_join_ptr(x / 16, str, i - 1);
		ft_join_ptr(x % 16, str, i);
	}
	if (x < 16)
	{
		if (x < 10)
			x = x + 48;
		else if (x >= 10)
			x = 87 + x;
		str[i] = x;
	}
}

char	*ft_join_pointer(char *ret, unsigned long ptr)
{
	char	*str;
	int		len;

	len = ft_digitcount_unsigned(ptr) - 2;
	str = malloc(sizeof(char) * len);
	str[0] = '0';
	str[1] = 'x';
	ft_join_ptr(ptr, str, len);
	ret = ft_realc_strjoin(ret, str);
	return (ret);
}

char	*ft_joinlen(char *ret, const char **content)
{
	int	i;
	int	start;

	i = ft_partlen(*content);
	start = ft_strlen(ret);
	ret = ft_realloc(ret, sizeof(char) * (start + i + 1));
	if (ret == NULL)
		return (0);
	while (i)
	{
		ret[start] = content[0][0];
		start++;
		content[0]++;
		i--;
	}
	ret[start] = '\0';
	return (ret);
}

char	*ft_joinchar(char *ret, int c)
{
	int	len;

	len = ft_strlen(ret);
	ret = ft_realloc(ret, len + 2);
	ret[len] = c;
	ret[len + 1] = '\0';
	return (ret);
}
