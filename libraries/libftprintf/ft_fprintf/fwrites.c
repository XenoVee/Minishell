/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fwrites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 17:04:38 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/29 15:31:57 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "../libft.h"

void	ft_fputhexadecimal_count(unsigned int x, int cap, size_t *wrt)
{
	if (x >= 0x10)
	{
		ft_fputhexadecimal_count(x / 0x10, cap, wrt);
		ft_fputhexadecimal_count(x % 0x10, cap, wrt);
	}
	if (x < 0x10)
	{
		if (x < 0xA)
			x = x + 48;
		else if (x >= 0xA)
			x = 87 + x - (32 * cap);
		wrt[0] += write(wrt[1], &x, 1);
	}
}

void	ft_fputnbr_count(int n, size_t *wrt)
{
	if (n == -2147483648)
	{
		wrt[0] += write(wrt[1], "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		wrt[0] += write(wrt[1], "-", 1);
		ft_fputnbr_count (-n, wrt);
		return ;
	}
	else if (n > 9)
	{
		ft_fputnbr_count (n / 10, wrt);
		ft_fputnbr_count (n % 10, wrt);
	}
	if (n > 9)
		return ;
	n = n + 48;
	wrt[0] += write(wrt[1], &n, 1);
	return ;
}

void	ft_fputnbr_unsigned_count(unsigned int n, size_t *wrt)
{
	if (n > 9)
	{
		ft_fputnbr_count (n / 10, wrt);
		ft_fputnbr_count (n % 10, wrt);
	}
	if (n > 9)
		return ;
	n = n + 48;
	wrt[0] += write(wrt[1], &n, 1);
	return ;
}

void	ft_fputstr_count(char *s, size_t *wrt)
{
	if (!s)
	{
		wrt[0] += write(wrt[1], "(null)", 6);
		return ;
	}
	wrt[0] += write(wrt[1], s, ft_strlen(s));
}
