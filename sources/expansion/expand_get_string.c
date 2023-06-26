/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_get_string.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 17:12:04 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/26 14:08:50 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include <unistd.h>
#include <stdlib.h>

void	copy_new_var(char *new, char *var, int *j)
{
	int	copy;

	copy = 0;
	while (var[copy])
	{
		new[*j] = var[copy];
		(*j)++;
		copy++;
	}
}

char	*get_new_string(char *old, char *new, int len, int index)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_string = (char *)malloc(sizeof(char) * len);
	if (!new_string)
		return (NULL);
	while (old[i])
	{
		if (old[i] == '$' && i == index)
		{
			copy_new_var(new, new_string, &j);
			i = i + var_length(old + index);
		}
		new[j++] = old[i++];
	}
	new[j] = '\0';
	return (new_string);
}