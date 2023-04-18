/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 19:57:28 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/19 17:27:58 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extend_malloc(char	*str, int size, int ext)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_calloc(sizeof(char), (size + ext));
	if (size == 0)
		return (ret);
	while (i < size && ret)
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	return (ret);
}

int	read_new(int fd, char *buf, int i)
{
	long int	rd;

	if (!buf[i])
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd > 0)
			buf[rd] = '\0';
		if (rd <= 0)
			return (-1);
		i = 0;
	}
	return (i);
}
