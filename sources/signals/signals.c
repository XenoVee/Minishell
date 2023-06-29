// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   signals.c                                          :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: Owen <Owen@student.codam.nl>                 +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2023/06/23 13:59:44 by Owen          #+#    #+#                 */
// /*   Updated: 2023/06/29 17:31:06 by Owen          ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "signals.h"

// /*Resets the readline user input prompt*/
// void	reset(int	temp)
// {
// 	(void)temp;
// 	write (1, "\n", 1);
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	rl_redisplay();
// }

// /*Prints a newline when a signal is caught*/
// void	signal_newline(int signal)
// {
// 	(void)signal;
// 	rl_on_new_line();
// }

// void	ignore_sigquit(void)
// {
// 	struct sigaction	ms;

// 	ft_memset(&ms, 0, sizeof(ms));
// 	ms.sa_handler = SIG_IGN;
// 	sigaction(SIGQUIT, &ms, NULL);
// }

// void	set_signals_interactive(void)
// {
// 	struct sigaction	ms;

// 	ignore_sigquit();
// 	ft_memset(&ms, 0, sizeof(ms));
// 	ms.sa_handler = &reset;
// 	sigaction(SIGINT, &ms, NULL);
// }


// void	set_signals_noninteractive(void)
// {
// 	struct sigaction	ms;

// 	ft_memset(&ms, 0, sizeof(ms));
// 	ms.sa_handler = &signal_newline;
// 	sigaction(SIGINT, &ms, NULL);
// 	sigaction(SIGQUIT, &ms, NULL);
// }