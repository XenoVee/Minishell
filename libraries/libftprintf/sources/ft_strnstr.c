/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:42:21 by rmaes             #+#    #+#             */
/*   Updated: 2022/06/13 17:19:42 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *ndl, size_t len)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	if (ndl[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + t] == ndl[t] && i + t < len)
		{
			t++;
			if (ndl[t] == '\0')
				return (&((char *)haystack)[i]);
		}
		t = 0;
		i++;
	}
	return (0);
}
