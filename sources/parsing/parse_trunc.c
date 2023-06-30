/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_trunc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 20:56:46 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/30 00:57:03 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"

static void	handle_trunc(t_data_fd *io, char *filename, char *o_filename)
{
	if (!remove_old_ref(io, false))
		return ;
	io->outfile = ft_strdup(filename);
	if (io->outfile && io->outfile[0] == '\0')
	{
		cmd_err_msg(o_filename, NULL, ERR_AR, false);
		return ;
	}
	io->fd_out = open(io->infile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (io->fd_out == -1)
		cmd_err_msg(io->outfile, NULL, strerror(errno), false);
}

void	parse_trunc(t_commands **cmd, t_token **list)
{
	t_commands	*last;
	t_token		*temp;

	last = lst_last_cmd(*cmd);
	temp = *list;
	init_data_fd(last);
	handle_trunc(last->fd_data, temp->next->string, temp->next->string_cpy);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*list = temp;
}
