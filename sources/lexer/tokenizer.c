	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        ::::::::            */
	/*   tokenizer.c                                        :+:    :+:            */
	/*                                                     +:+                    */
	/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
	/*                                                   +#+                      */
	/*   Created: 2023/06/23 15:17:22 by Owen          #+#    #+#                 */
	/*   Updated: 2023/06/28 20:04:19 by Owen          ########   odam.nl         */
	/*                                                                            */
	/* ************************************************************************** */

	#include "lexer.h"
	#include <stdio.h>

	int	set_status(int status, char *str, int i)
	{
		if (str[i] == '\'' && status == DEFAULT)
			status = S_QUOTES;
		else if (str[i] == '\"' && status == DEFAULT)
			status = D_QUOTES;
		else if (str[i] == '\'' && status == S_QUOTES)
			status = DEFAULT;
		else if (str[i] == '\"' && status == D_QUOTES)
			status = DEFAULT;
		return (status);
	}

	int	tokenizer(t_data *data, char *str)
	{
		int		i;
		int		start;
		int		end;
		int		status;

		i = -1;
		start = 0;
		end = ft_strlen(str);
		status = DEFAULT;
		while (++i <= end)
		{
			status = set_status(status, str, i);
			if (status == DEFAULT)
				start = save_part(data, &i, str, start);
		}
		if (status != DEFAULT)
		{
			if (status == D_QUOTES)
				printf("error, unexpected EOF while looking for matching \"\n");
			if (status == S_QUOTES)
				printf("error, unexpected EOF while looking for matching \'\n");
		}
		return (0);
	}
