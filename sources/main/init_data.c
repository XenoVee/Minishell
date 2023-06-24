/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 20:42:45 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/24 21:10:29 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "structs.h"

int	env_var_count(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

static bool	init_env(t_data *data, char **env)
{
	int	i;
	
	i = 0;
	printf("setting up a copy of env\n");
	data->env_cpy = ft_calloc(env_var_count(env) + 1, sizeof * data->env_cpy);
	if (!data->env_cpy)
	{
		printf("calloc error\n");
		return (false);
	}
	while (env[i])
	{
		data->env_cpy[i] = ft_strdup(env[i]);
		if (!data->env_cpy[i])
		{
			printf("cloning failed\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_data(t_data *data, char **env)
{
	if (init_env(data, env) == false)
		return (NULL);
	data->token = NULL;
	data->user_input = NULL;
	data->cmd = NULL;
	//g_exit_code = 0;
	return (true);
}
