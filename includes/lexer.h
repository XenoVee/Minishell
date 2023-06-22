/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   tokenizer.h										:+:	:+:			*/
/*													 +:+					*/
/*   By: ohearn <ohearn@student.codam.nl>			 +#+					 */
/*												   +#+					  */
/*   Created: 2023/04/19 13:44:45 by ohearn		#+#	#+#				 */
/*   Updated: 2023/05/19 18:19:41 by ohearn		########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define EOS 		1
# define DELIMS 	" \t\r\n\v\f"
# define END_STR	" \t\r\n\v\f<>|"
# include "../libraries/dl_list/include/dl_list.h"

/*Structs*/
typedef enum e_token_type
{
	EMPTY = 0,
	TOKEN_ARG,
	TOKEN_IN,
	TOKEN_OUT,
	TOKEN_PIPE,
	TOKEN_NOEX,
	DOUBLE_LESSER,
	DOUBLE_GEATER,
	S_QUOTES,
	D_QUOTES,
	DOLLARSGN,
	END,
}	t_token_type;

typedef enum e_status
{
	DEFAULT = 0,
	S_Q,
	D_Q,
}	t_status;

typedef struct s_commands
{
	t_dllist		*args;
	t_dllist		*outf;
	t_dllist		*inf;
}		t_commands;

typedef struct s_token
{
	t_token_type	type;
	char			*string;
	int				status;
}		t_token;

typedef struct s_lexer
{
	int				pos;
	t_token_type	type;
	int				start;
	char			*content;
	int				end;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_data
{
	t_token		*token;
	t_lexer		*lexer;
	char		*user_input;
	char		*current_dir;
	char		*old_dir;
	t_commands	*cmd;
}		t_data;


/*Functions*/
// void		free_token(t_token *token);
// int		is_delim(char c);
// char		*find_char(const char *str, char c);
// char		*split_string(const char *str, const char *delims);
bool		build_lexer(t_data *data);

#endif