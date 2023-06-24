/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:44:45 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/24 13:38:32 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define SUCCESS	0
# define FAILURE	1
# define DELIMS 	" \t\r\n\v\f"
# define END_STR	" \t\r\n\v\f<>|"
# include <stdbool.h>
# include <stdlib.h>
# include "../libraries/libftprintf/libft.h"

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
	bool			var;
	int				status;
	struct s_token	*next;
	struct s_token	*prev;
}		t_token;

typedef struct s_commands
{
	char				*path;
	char				*command;
	char				**args;
	struct s_command	*next;
	struct s_command	*prev;
	
}		t_commands;

typedef struct s_data
{
	t_token		*token;
	char		**env_cpy;
	char		*user_input;
	char		*current_dir;
	char		*old_dir;
	t_commands	*cmd;
}		t_data;


/*Functions*/
//bool		build_lexer(t_data *data);
//int		skip_delims(char *str, int i);
bool		parse_input_str(t_data *data);
int			tokenizer(t_data *data, char *str);
int			save_part(t_data *data, int *i, char *str, int start);

/*list functions*/
t_token		*new_token(char *str, char *str_cpy, int type, int status);
void		lst_add_back_tkn(t_token **lst, t_token *new);
void		lst_delone_tkn(t_token *lst, void (*del)(void *));

#endif