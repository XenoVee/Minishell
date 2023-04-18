/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 16:42:28 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/26 00:57:53 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	trim(char const *s1, char const *set, int loc, int dir)
{
	int	loop;
	int	i;

	i = 0;
	loop = 0;
	while (loop != -1 && s1[loc] && (loc > 0 || dir == 1))
	{
		while (set[i] && set[i] != s1[loc])
			i++;
		if (set[i] != s1[loc])
			loop = -1;
		else
			loc = loc + dir;
		i = 0;
	}
	if (!s1[loc])
		return (-1);
	return (loc);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		start;
	int		end;

	if (!s1)
		return (0);
	if (!set)
	{
		ret = ft_substr(s1, 0, ft_strlen(s1));
		if (ret == 0)
			return (0);
		return (ret);
	}
	start = trim(s1, set, 0, 1);
	end = trim(s1, set, ft_strlen(s1) - 1, -1);
	if (start == -1 || end == -1)
		ret = ft_calloc(1, sizeof(char));
	else
		ret = ft_substr(s1, start, end - start + 1);
	if (ret == 0)
		return (0);
	return (ret);
}
