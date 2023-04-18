/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/28 14:47:15 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/18 17:04:14 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_partlen(const char *s, size_t start)
{
	int	a;

	a = start;
	while (s[a] != '%' && s[a])
		a++;
	return (a);
}
