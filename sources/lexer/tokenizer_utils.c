/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/21 11:25:00 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/16 16:25:34 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_token(t_token *token)
{
	free(token->string);
}

t_token_type    id_quote(char c)
{
    if (c == '\'')
        return (S_QUOTES);
    if (c == '\"')
        return (D_QUOTES);
    return (TOKEN_ARG);
}

t_token    init_tkn(void)
{
    t_token    new;

    new.type = 0;
    new.status = 0;
    new.string = NULL;
    return (new);
}
