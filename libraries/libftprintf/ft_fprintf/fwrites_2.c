/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fwrites_2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 17:04:38 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/29 15:31:18 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_fput_ptr_count(unsigned long x, size_t *wrt)
{
	if (x >= 16)
	{
		ft_fput_ptr_count(x / 16, wrt);
		ft_fput_ptr_count(x % 16, wrt);
	}
	if (x < 16)
	{
		if (x < 10)
			x = x + 48;
		else if (x >= 10)
			x = 87 + x;
		wrt[0] += write(wrt[1], &x, 1);
	}
}

void	ft_fpointer_count(unsigned long ptr, size_t *wrt)
{
	wrt[0] += write(wrt[1], "0x", 2);
	ft_fput_ptr_count(ptr, wrt);
}

void	ft_fputlen(const char *s, size_t len, size_t start, size_t *wrt)
{
	wrt[0] += write(wrt[1], &s[start], len - start);
}

void	ft_fputchar_count(int c, size_t *wrt)
{
	wrt[0] += write(wrt[1], &c, 1);
}
