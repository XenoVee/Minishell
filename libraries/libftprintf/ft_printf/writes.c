/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 17:04:38 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/18 17:04:40 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

void	ft_puthexadecimal_count(unsigned int x, int cap, size_t *wrt)
{
	if (x >= 0x10)
	{
		ft_puthexadecimal_count(x / 0x10, cap, wrt);
		ft_puthexadecimal_count(x % 0x10, cap, wrt);
	}
	if (x < 0x10)
	{
		if (x < 0xA)
			x = x + 48;
		else if (x >= 0xA)
			x = 87 + x - (32 * cap);
		*wrt += write (1, &x, 1);
	}
}

void	ft_putnbr_count(int n, size_t *wrt)
{
	if (n == -2147483648)
	{
		*wrt += write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		*wrt += write (1, "-", 1);
		ft_putnbr_count (-n, wrt);
		return ;
	}
	else if (n > 9)
	{
		ft_putnbr_count (n / 10, wrt);
		ft_putnbr_count (n % 10, wrt);
	}
	if (n > 9)
		return ;
	n = n + 48;
	*wrt += write (1, &n, 1);
	return ;
}

void	ft_putnbr_unsigned_count(unsigned int n, size_t *wrt)
{
	if (n > 9)
	{
		ft_putnbr_count (n / 10, wrt);
		ft_putnbr_count (n % 10, wrt);
	}
	if (n > 9)
		return ;
	n = n + 48;
	*wrt += write (1, &n, 1);
	return ;
}

void	ft_putstr_count(char *s, size_t *wrt)
{
	if (!s)
	{
		*wrt += write(1, "(null)", 6);
		return ;
	}
	*wrt += write(1, s, ft_strlen(s));
}
