/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   null_check.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 14:31:51 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/19 15:18:13 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	null_exit(void)
{
	perror("minishell");
	exit(EXIT_FAILURE);
}

/*Checks if the given pointer is null*/
void	*null_check(void *ptr)
{
	if (!ptr)
		return (NULL);
	return (ptr);
}