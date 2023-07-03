/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_heredoc.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 00:11:59 by Owen          #+#    #+#                 */
/*   Updated: 2023/07/03 15:50:40 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "parsing.h"
#include "signals.h"

bool	fill_heredoc(t_data *data, t_data_fd *io, int fd)
{
	char	*input;
	bool	success;

	success = false;
	input = NULL;
	while (true)
	{
		set_signals_interactive();
		input = readline(">");
		set_signals_noninteractive();
		if (check_line_hd(data, io, &input, &success) == false)
			break ;
		ft_putendl_fd(input, fd);
		free_pointer(input);
	}
	free_pointer(input);
	return (success);
}

bool	build_heredoc(t_data *data, t_data_fd *io)
{
	bool	ret;
	int		temp_fd;

	ret = true;
	temp_fd = open(io->infile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ret = fill_heredoc(data, io, temp_fd);
	close(temp_fd);
	return (ret);
}

void	parse_heredoc(t_data *data, t_commands **last_cmd, t_token **list)
{
	t_token		*temp;
	t_commands	*cmd;
	t_data_fd	*io;

	temp = *list;
	cmd = lst_last_cmd(*last_cmd);
	init_data_fd(cmd);
	io = cmd->fd_data;
	if (!remove_old_ref(io, true))
		return ;
	io->infile = get_heredoc_name();
	io->delim_hd = get_delim_hd(temp->next->string, io->quotes_hd);
	if (build_heredoc(data, io))
		io->fd_in = open(io->infile, O_RDONLY);
	else
		io->fd_in = -1;
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*list = temp;
}
