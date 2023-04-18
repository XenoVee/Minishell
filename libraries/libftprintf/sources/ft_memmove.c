/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:41:51 by rmaes             #+#    #+#             */
/*   Updated: 2022/06/13 17:18:50 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	overlap_check(char *d, const char *s, size_t len)
{
	size_t	i;
	int		overlap;

	i = 0;
	overlap = 0;
	while (i < len && overlap == 0)
	{
		if (&s[i] == &d[0])
			overlap = -1;
		else
			i++;
	}
	return (overlap);
}

void	*ft_memmove(void *d, const void *s, size_t len)
{
	size_t	i;

	if (!s && !d)
		return (d);
	i = 0;
	if (overlap_check(d, s, len) == -1)
	{
		i += len;
		while (i > 0)
		{
			i--;
			((char *)d)[i] = ((char *)s)[i];
		}
	}
	else
	{
		while ((i < len))
		{
			((char *)d)[i] = ((char *)s)[i];
			i++;
		}
	}
	return (d);
}
