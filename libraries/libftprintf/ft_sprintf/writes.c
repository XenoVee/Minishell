/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/01 17:04:38 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/12 16:59:45 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"
#include "../libft.h"

// void	ft_joinhexadecimal_count(unsigned int x, int cap)
// {
// 	if (x >= 0x10)
// 	{
// 		ft_joinhexadecimal_count(x / 0x10, cap, wrt);
// 		ft_joinhexadecimal_count(x % 0x10, cap, wrt);
// 	}
// 	if (x < 0x10)
// 	{
// 		if (x < 0xA)
// 			x = x + 48;
// 		else if (x >= 0xA)
// 			x = 87 + x - (32 * cap);
// 		*wrt += write (1, &x, 1);
// 	}
// }

// void	ft_joinnbr_count(int n)
// {
// 	if (n == -2147483648)
// 	{
// 		*wrt += write(1, "-2147483648", 11);
// 		return ;
// 	}
// 	else if (n < 0)
// 	{
// 		*wrt += write (1, "-", 1);
// 		ft_joinnbr_count (-n, wrt);
// 		return ;
// 	}
// 	else if (n > 9)
// 	{
// 		ft_joinnbr_count (n / 10, wrt);
// 		ft_joinnbr_count (n % 10, wrt);
// 	}
// 	if (n > 9)
// 		return ;
// 	n = n + 48;
// 	*wrt += write (1, &n, 1);
// 	return ;
// }

// void	ft_joinnbr_unsigned_count(unsigned int n)
// {
// 	if (n > 9)
// 	{
// 		ft_joinnbr_count (n / 10, wrt);
// 		ft_joinnbr_count (n % 10, wrt);
// 	}
// 	if (n > 9)
// 		return ;
// 	n = n + 48;
// 	*wrt += write (1, &n, 1);
// 	return ;
// }

char	*ft_joinstr(char *ret, char *s)
{
	if (!s)
		return (ret);
	ret = ft_realc_strjoin(ret, s);
	return (ret);
}
