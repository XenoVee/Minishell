/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:42:05 by rmaes             #+#    #+#             */
/*   Updated: 2022/06/13 17:18:59 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((unsigned char) s[i] != (unsigned char) c && s[i] != '\0')
		i++;
	if ((unsigned char) s[i] == (unsigned char) c)
		return ((char *)&s[i]);
	return (0);
}
