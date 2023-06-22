/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 20:42:45 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/22 17:19:11 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

// static bool	init_env(t_data *data, char **env)
// {
// 	int	i;
	
// 	i = 0;
// 	data->env = ft_calloc(env_var_count(env) + 1, sizeof * data->env);
// 	if (!data->env)
// 		return (false);
// 	while (env[i])
// 	{
// 		data->env = ft_strdup(env[i]);
// 		if (!data->env[i])
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }

bool	init_data(t_data *data)
{
	// if (!init_env(data, env) == false)
	// 	return (NULL);
	data->lexer = NULL;
	data->token = NULL;
	data->user_input = NULL;
	data->cmd = NULL;
	//g_exit_code = 0;
	return (true);
}
