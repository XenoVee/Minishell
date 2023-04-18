/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 19:58:02 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/19 17:27:54 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	bufcopy(char *ret, char *buf, int *i, int j)
{
	while (buf[*i] != '\n' && *i < BUFFER_SIZE && buf[*i] != '\0')
	{
		ret[j] = buf[*i];
		j++;
		(*i)++;
	}
	return (j);
}

static char	*loop(char	*ret, char *buf, int fd, int *i)
{
	int	j;

	j = 0;
	while ((*i != -1 || j == 0))
	{	
		*i = read_new(fd, buf, *i);
		if (*i == -1 && ret == NULL)
			return (NULL);
		ret = extend_malloc(ret, j, BUFFER_SIZE);
		if (ret == NULL)
			return (NULL);
		j = bufcopy(ret, buf, i, j);
		if (buf[*i] == '\n')
		{
			ret[j] = buf[*i];
			(*i)++;
			ret[j + 1] = '\0';
			return (ret);
		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	buf[BUFFER_SIZE + 1];
	static int	i = 0;

	if (fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	str = NULL;
	return (loop(str, buf, fd, &i));
}
