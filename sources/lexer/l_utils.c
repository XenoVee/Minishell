/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   l_utils.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 22:16:05 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/22 19:46:32 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

int	skip_delims(char *str, int i)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}