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

#ifndef TOKENIZER_H
# define TOKENIZER_H

# define EOS 1

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
	PIPE,
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
	t_dllist	*args;
	t_dllist	*outf;
	t_dllist	*inf;
}		t_commands;

typedef struct s_token
{
	t_token_type	type;
	char			*string;
	int				status;
}		t_token;

typedef struct s_data
{
	t_token	token;
	char	*user_input;
}		t_data;

/*Functions*/
void	free_token(t_token *token);
int		is_delim(char c);
char	*find_char(const char *str, char c);
char	*split_string(const char *str, const char *delims);

#endif