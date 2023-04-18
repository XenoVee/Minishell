/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:42:13 by rmaes             #+#    #+#             */
/*   Updated: 2022/06/13 17:19:31 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	len = ft_strlen(dst);
	while (src[i] && i + len + 1 < size)
	{
		dst[i + len] = src[i];
		i++;
	}
	if (len < size)
		dst[i + len] = '\0';
	while (src[i])
		i++;
	if (size < len)
		return (i + size);
	else
		return (len + i);
}
