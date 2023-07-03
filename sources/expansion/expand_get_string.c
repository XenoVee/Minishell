/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_get_string.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 17:12:04 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:44:25 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	copy_new_var(char *new, char *var, int *j)
{
	int	copy;

	copy = 0;
	printf("var is %s\n", var);
	while (var[copy])
	{
		new[*j] = var[copy];
		(*j)++;
		copy++;
	}
}

char	*get_new_string(char *old, char *var, int len, int index)
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
			copy_new_var(new_string, var, &j);
			i = i + var_length(old + index) + 1;
			if (old[i] == '\0')
				break ;
		}
		new_string[j++] = old[i++];
	}
	new_string[j] = '\0';
	return (new_string);
}
