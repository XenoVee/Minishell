/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 17:54:01 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:42:44 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_data(t_data *data, t_token *token)
{
	t_token	*temp;

	if (token->type == END)
		return ;
	temp = token;
	while (temp->next != NULL)
	{
		if (temp == token)
			lst_add_back_cmd(&data->cmd, lst_new_command());
		if (temp->type == HEREDOC)
			parse_heredoc(data, &data->cmd, &temp);
		else if (temp->type == WORD || temp->type == VAR)
			parse_word(&data->cmd, &temp);
	}
	return ;
}
