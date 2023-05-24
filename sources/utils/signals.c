/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 13:46:13 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/24 14:29:24 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*Attempt at using sigaction and readline for testing purposes,
but will be put on hold for now until I have time to sort it out*/
void	sig_stuff(void)
{
	struct sigaction	ms;

	ft_memset(&ms, 0, sizeof(ms));
	ms.sa_handler = SIG_DFL;
	sigaction(SIGINT, &ms, NULL);
	sigaction(SIGQUIT, &ms, NULL);
}

int	mini_loop(t_data *data)
{
	t_dllist	*str_list;
	char	*str;

	str_list = NULL;
	while (true)
	{
		sig_stuff();
		data->user_input = readline("Minishell>$");
		if (!data->user_input)
			break ;
		add_history(data->user_input);
		dll_add_back(&str_list, dl_new_list(str));
		parse_input(data->user_input);
		free (data->user_input);
	}
	return (1);
}
