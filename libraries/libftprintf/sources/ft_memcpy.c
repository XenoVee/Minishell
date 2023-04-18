/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 16:41:49 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/26 00:55:51 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		a;
	char		*dsttemp;
	const char	*srctemp;

	srctemp = src;
	dsttemp = dst;
	if (src == NULL && dst == NULL)
	{
		return (0);
	}
	a = 0;
	while (a < n)
	{
		dsttemp[a] = srctemp[a];
		a++;
	}
	return (dsttemp);
}
