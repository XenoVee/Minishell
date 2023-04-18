/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 18:03:31 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/04 18:04:06 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// make sure n is at least d - return largest
int	ft_max(int n, int d)
{
	if (n < d)
		return (d);
	return (n);
}
