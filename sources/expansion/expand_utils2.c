/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_utils2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 14:54:20 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/27 16:43:30 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char	*id_variable(char *string)
{
	char	*var;
	int		start;
	int		size;
	int		i;

	i = 0;
	start = 0;
	printf("string is %s\n", string);
	while (string[i])
	{
		if (string[i] == '$')
		{
			start = i + 1;
			break ;
		}
		i++;
	}
	size = var_length(string);
	var = ft_substr(string, start, size);
	if (!var)
		return (NULL);
	printf("var is now : %s\n", var);
	return (var);
}

bool	valid_var(t_data *data, char *var)
{
	char	*temp;

	temp = ft_getenv(data->env, var);
	if (temp == NULL)
		return (false);
	return (true);
}