/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/23 17:47:44 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Attempt at using sigaction and readline for testing purposes,
but will be put on hold for now until I have time to sort it out*/
void	sig_stuff(void)
{
	struct sigaction	ms;

	ft_memset(&ms, 0, sizeof(ms));
	ms.sa_handler = SIG_DFL;
	sigaction(SIGINT, &ms, NULL);
}

void	mini_loop(t_data *data)
{
	while (1)
	{
		sig_stuff();
		data->user_input = readline("Minishell>$");
		add_history(data->user_input);
		check_token(data->user_input);
		free (data->user_input);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	char	*test;

	(void)ac;
	(void)av;
	test = "This is a < test";
	printf("Start!\n");
	ft_memset(&data, 0, sizeof(t_data));
	if (!init_data(data))
		exit(FAILURE);
	mini_loop(&data);
	ft_printf("minishell\n");
	return (0);
}
