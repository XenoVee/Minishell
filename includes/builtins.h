/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:56:35 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/28 15:31:17 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*enums*/
enum e_flag
{
	FALSE = 0,
	TRUE,
};

/*functions*/
void	bi_echo(t_commands *cmd);
void	bi_env(t_dllist *env);
void	bi_unset(t_commands *cmd, t_dllist *env);
void	bi_export(t_commands *cmd, t_dllist *env);
void	bi_pwd(void);
int		bi_cd(t_dllist *env, t_commands *cmd);

#endif