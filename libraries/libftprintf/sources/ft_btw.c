/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_btw.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 18:03:51 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/10 15:42:11 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// make sure n is between d and i
int	ft_btw(int n, int d, int i)
{
	if (i < d)
		return (ft_max(ft_min(n, d), i));
	else if (i == d)
		return (d);
	else
		return (ft_max(ft_min(n, i), d));
}
