/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 01:49:40 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:44:22 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"
#include "cleanup.h"
#include "structs.h"
#include <stdio.h>

int	var_length(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i] != '$')
		i++;
	i++;
	if ((string[i] >= '0' && string[i] <= '9') || string[i] == '?')
		return (count + 1);
	while (string[i])
	{
		if (ft_isalnum(string[i]) == 1 && string[i] != '_')
		{
			i++;
			count++;
		}
		else
			break ;
	}
	return (count);
}

static bool	erase_variable(t_token **list, char *string, int index)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = 0;
	j = 0;
	len = ft_strlen(string) - var_length(string + index);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (false);
	while (string[i])
	{
		if (string[i] == '$' && i == index)
		{
			i = i + var_length(string + index);
			if (string[i] == '\0')
				break ;
		}
		new[j++] = string[i++];
	}
	new[j] = '\0';
	free_pointer((*list)->string);
	(*list)->string = new;
	return (true);
}

static bool	erase_replace_var(t_token **list, char *string,
				char *var, int index)
{
	int		len;
	char	*new;

	len = (ft_strlen(string) - var_length(string + index) + ft_strlen(var));
	new = get_new_string(string, var, len, index);
	if (!new)
		return (false);
	if (list && *list)
	{
		free_pointer((*list)->string);
		(*list)->string = new;
	}
	return (true);
}

void	replace_var(t_token **list, char *var, int index)
{
	if (var == NULL)
	{
		if (erase_variable(list, (*list)->string, index) == false)
		{
			free_pointer(var);
			return ;
		}
	}
	else
	{
		if (erase_replace_var(list, (*list)->string, var, index) == false)
		{
			free_pointer(var);
			return ;
		}
	}
	free_pointer(var);
}
