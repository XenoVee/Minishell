/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/29 20:18:43 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/30 00:56:42 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error.h"

bool	remove_old_ref(t_data_fd *io, bool infile)
{
	if (infile == true && io->infile)
	{
		if (io->fd_in == -1)
			return (false);
		if (io->delim_hd != NULL)
		{
			free_pointer(io->delim_hd);
			io->delim_hd = NULL;
			unlink(io->infile);
		}
		free_pointer(io->infile);
		close(io->fd_in);
	}
	else if (infile == false && io->outfile)
	{
		if (io->fd_out == -1 || (io->infile && io->fd_in == -1))
			return (false);
		free_pointer(io->outfile);
		close(io->fd_out);
	}
	return (true);
}

static void	handle_infile(t_data_fd *io, char *filename, char *o_filename)
{
	if (!remove_old_ref(io, true))
		return ;
	io->infile = ft_strdup(filename);
	if (io->infile && io->infile[0] == '\0')
	{
		cmd_err_msg(o_filename, NULL, ERR_AR, false);
		return ;
	}
	io->fd_in = open(io->infile, O_RDONLY);
	if (io->fd_in == -1)
		cmd_err_msg(io->infile, NULL, strerror(errno), false);
}

void	parse_input(t_commands **cmd, t_token **list)
{
	t_commands	*last;
	t_token		*temp;

	last = lst_last_cmd(*cmd);
	temp = *list;
	init_data_fd(last);
	handle_infile(last->fd_data, temp->next->string, temp->next->string_cpy);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*list = temp;
}
