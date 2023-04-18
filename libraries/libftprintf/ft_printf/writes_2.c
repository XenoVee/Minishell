/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:04:38 by rmaes             #+#    #+#             */
/*   Updated: 2022/08/16 15:57:52 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr_count(unsigned long x, size_t *wrt)
{
	if (x >= 16)
	{
		ft_put_ptr_count(x / 16, wrt);
		ft_put_ptr_count(x % 16, wrt);
	}
	if (x < 16)
	{
		if (x < 10)
			x = x + 48;
		else if (x >= 10)
			x = 87 + x;
		*wrt += write (1, &x, 1);
	}
}

void	ft_pointer_count(unsigned long ptr, size_t *wrt)
{
	*wrt += write(1, "0x", 2);
	ft_put_ptr_count(ptr, wrt);
}

void	ft_putlen(const char *s, size_t len, size_t start, size_t *wrt)
{
	*wrt += write(1, &s[start], len - start);
}

void	ft_putchar_count(int c, size_t *wrt)
{
	*wrt += write(1, &c, 1);
}
