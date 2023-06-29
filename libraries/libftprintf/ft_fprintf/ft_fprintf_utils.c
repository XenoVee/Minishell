/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fprintf_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/28 14:47:15 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/29 15:24:49 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_fpartlen(const char *s, size_t start)
{
	int	a;

	a = start;
	while (s[a] != '%' && s[a])
		a++;
	return (a);
}
