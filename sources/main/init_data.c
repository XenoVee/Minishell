/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 20:42:45 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/27 16:07:03 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error.h"
#include "structs.h"

bool	init_data(t_data *data, char **env)
{
	data->token = NULL;
	data->env = envcpy(env);
	if (!data->env)
		return (NULL);
	//printf("Does env exist? %s\n", data->env->head->name);
	data->user_input = NULL;
	data->cmd = NULL;
	//g_exit_code = 0;
	return (true);
}
