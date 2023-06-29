/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/24 14:15:35 by Owen          #+#    #+#                 */
/*   Updated: 2023/06/29 13:58:20 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*to-do: move the structs from lexer into this header file*/
# include "env.h"
# include <stdbool.h>

/*Structs*/
typedef enum e_token_type
{
	SPACES = 1,
	WORD,
	VAR,
	PIPE,
	INPUT,
	TRUNC,
	HEREDOC,
	APPEND,
	END
}	t_token_type;

typedef enum e_status
{
	DEFAULT = 0,
	S_QUOTES,
	D_QUOTES,
}	t_status;

typedef struct s_token
{
	t_token_type	type;
	char			*string;
	char			*string_cpy;
	bool			valid_var;
	int				status;
	struct s_token	*next;
	struct s_token	*prev;
}		t_token;

typedef struct s_commands
{
	char				**args;
	struct s_commands	*next;
	struct s_commands	*prev;
}		t_commands;

typedef struct s_data
{
	t_token		*token;
	t_dllist	*env;
	char		*user_input;
	char		*current_dir;
	char		*old_dir;
	t_commands	*cmd;
}		t_data;

#endif