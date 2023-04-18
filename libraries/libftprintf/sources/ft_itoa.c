/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 16:41:37 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/20 20:16:06 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static char	*swap(char	*d)
{
	int		i;
	int		ir;
	char	tmp;

	i = 0;
	if (d[0] == '-')
		i++;
	ir = ft_strlen(d) - 1;
	while (i <= ir)
	{
		tmp = d[i];
		d[i] = d[ir];
		d[ir] = tmp;
		i++;
		ir--;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*ret;
	int		len;

	len = ft_digitcount(n) + 1 + ft_is_negative(n);
	i = 0;
	ret = ft_calloc(len, sizeof(char));
	if (!ret)
		return (0);
	if (n < 0)
	{
		ret[i] = '-';
		i++;
	}
	while (n != 0 || i == 0)
	{
		ret[i] = ft_abs((n % 10)) + 48;
		n = n / 10;
		i++;
	}
	ret[i] = '\0';
	return (swap(ret));
}
