/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:44:45 by ohearn        #+#    #+#                 */
/*   Updated: 2023/06/29 11:22:22 by Owen          ########   odam.nl         */
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
# include "structs.h"
# include "../libraries/libftprintf/libft.h"

/*Functions*/
bool		parse_input_str(t_data *data);
int			tokenizer(t_data *data, char *str);
int			save_part(t_data *data, int *i, char *str, int start);
bool		check_for_var(t_token **t_list);

/*list functions*/
t_token		*new_token(char *str, char *str_cpy, int type, int status);
void		lst_add_back_tkn(t_token **lst, t_token *new);
void		lst_delone_tkn(t_token *lst, void (*del)(void *));
void		lst_clear_tkn(t_token **list, void (*del)(void *));

#endif