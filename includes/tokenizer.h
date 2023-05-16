/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 13:44:45 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/16 16:18:26 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# define EOS 1

/*Structs*/
typedef enum e_token_type
{
    NONE = 0,
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
}    t_token_type;

/*Functions*/
void	free_token(t_token *token);
int		is_delim(char c);
char	*find_char(char *str, char c);

#endif