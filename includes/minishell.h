/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/18 17:43:14 by ohearn        #+#    #+#                 */
/*   Updated: 2023/05/02 20:14:03 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "../libraries/libftprintf/libft.h"
# include "../libraries/cdl_list/include/cdl_list.h"

/*Defines*/

/*Structs*/

/*Functions*/
void	check_token(char *string);
void	test(void);

/*executor*/
int		executor(char *cmd, char **envp, char **argv);
char	*pathfinder(char *find);

#endif