/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 13:46:13 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/15 15:29:09 by ohearn        ########   odam.nl         */
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

int	mini_loop(void)
{
	t_dllist	*str_list;
	char		*str;

	str_list = NULL;
	while (true)
	{
		sig_stuff();
		str = readline("Minishell>$");
		if (!str)
			break ;
		add_history(str);
		dll_add_back(&str_list, dl_new_list(str));
		if (ft_strncmp(str, "exit", 5))
			break ;
		parse_input(str);
	}
	dll_clear(&str_list, free);
	return (1);
}
