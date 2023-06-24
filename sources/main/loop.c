/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 13:46:13 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/24 13:35:38 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/lexer.h"
#include "../includes/loop.h"
#include "signals.h"

/*Attempt at using sigaction and readline for testing purposes,
but will be put on hold for now until I have time to sort it out*/
// void	sig_stuff(void)
// {
// 	struct sigaction	ms;

// 	ft_memset(&ms, 0, sizeof(ms));
// 	ms.sa_handler = SIG_DFL;
// 	sigaction(SIGINT, &ms, NULL);
// 	sigaction(SIGQUIT, &ms, NULL);
// }

// int	mini_loop(t_data *data)
// {
// 	while (true)
// 	{
// 		set_signals_interactive();
// 		data->user_input = readline("Minishell>$");
// 		if (!data->user_input)
// 			break ;
// 		if (ft_strlen(data->user_input) == 0)
// 		{
// 			free(data->user_input);
// 			continue ;
// 		}
// 		add_history(data->user_input);
// 		if (build_lexer(data) == false)
// 		{
// 			printf("broken :(\n)");
// 			exit (42);
// 		}
// 		if (check_lexer(data) == false)
// 			exit (42);
// 	}
// 	return (1);
// }

int	mini_loop(t_data *data)
{
	while (true)
	{
		set_signals_interactive();
		data->user_input = readline("Minishell>$");
		set_signals_noninteractive();
		if (parse_input_str(data) == true)
			printf("happy :D\n");
		break ;
	}
	return (0);
}
