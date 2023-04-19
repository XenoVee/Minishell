/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/19 18:50:48 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "minishell.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		printf("try again\n");
		return (-1);
	}
	while (argv[i])
	{
		check_token(argv[i], 0);
		i++;
	}
	ft_printf("minishell\n");
	return (0);
}
