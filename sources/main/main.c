/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:40:12 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/27 13:41:54 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "lexer.h"
#include "structs.h"
#include "loop.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "builtins.h"

int	second_main(int argc, char **argv, char **envp)
{
	t_dllist	*env;

	(void)argc;
	env = envcpy(envp);
	bi_cd(env, argv[1]);
	//argc++;
	if (argv[0])
		;
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac > 1)
	{
		second_main(ac, av, env);
		return (1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	if (!init_data(&data, env))
		exit_ms(NULL, 0);
	mini_loop(&data);
	return (0);
}
