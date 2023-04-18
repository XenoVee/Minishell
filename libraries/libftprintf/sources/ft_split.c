/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:42:02 by rmaes             #+#    #+#             */
/*   Updated: 2022/06/13 17:18:58 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	if (s[ft_strlen(s) - 1] == c)
		count--;
	return (count);
}

static void	*free_array(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	**split(char const *s, char c, char **array, int count)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (s[i] && j < count)
	{
		while (s[i] == c)
			i++;
		while (s[i + tmp] != c && s[i + tmp])
			tmp++;
		array[j] = ft_substr(&s[i], 0, tmp);
		if (array[j] == 0)
			return (free_array(array, j));
		i = i + tmp;
		j++;
		tmp = 0;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;

	if (!s)
		return (0);
	else if (!s[0])
	{
		array = ft_calloc(1, sizeof(char *));
		if (array == 0)
			return (0);
		array[0] = 0;
		return (array);
	}
	count = word_count(s, c);
	array = ft_calloc((count + 1), sizeof(char *));
	if (array == 0)
		return (0);
	array[count] = 0;
	return (split(s, c, array, count));
}
