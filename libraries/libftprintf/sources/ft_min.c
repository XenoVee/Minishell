/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 18:02:20 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/04 18:03:01 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// make sure n is at most d - return smallest
int	ft_min(int n, int d)
{
	if (n > d)
		return (d);
	return (n);
}
