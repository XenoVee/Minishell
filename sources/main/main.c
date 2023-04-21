/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/21 09:58:14 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av)
{
	int		i;
	t_data	data;

	i = 1;
	if (ac < 2)
	{
		printf("try again\n");
		return (-1);
	}
	if (!init_data(&data))
		exit(FAILURE);
	while (av[i])
	{
		check_token(av[i], 0);
		i++;
	}
	ft_printf("minishell\n");
	return (0);
}
