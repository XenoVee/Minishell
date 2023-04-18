/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uns_digitcount.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 18:18:57 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/20 18:36:29 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_digitcount_unsigned(unsigned long int n)
{
	int	i;

	i = 0;
	while (n != 0 || i == 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
