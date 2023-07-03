/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 13:46:13 by ohearn        #+#    #+#                 */
/*   Updated: 2023/07/03 16:16:08 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/lexer.h"
#include "../includes/structs.h"
#include "../includes/loop.h"
#include "signals.h"
#include "cleanup.h"
#include "error.h"

int	mini_loop(t_data *data)
{
	while (true)
	{
		set_signals_interactive();
		data->user_input = readline("Minishell>$");
		set_signals_noninteractive();
		if (data->user_input[0] == 'x')
			break ;
		if (parse_input_str(data) == true)
			printf("happy :D\n");
		free_data(data, false);
	}
	return (0);
}
