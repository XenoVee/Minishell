/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 13:56:35 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/25 13:56:49 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*enums*/

// bitmask
enum e_mask
{
	M_NONE = 0,
	M_N = 1,
	M_EXP = 2,
	M_EXP_N = 3,
};

/*functions*/
void	bi_echo(char *str, t_dllist *env, int mode);
void	bi_env(t_dllist *env);
void	bi_unset(char *var, t_dllist *env);
void	bi_export(char *var, t_dllist *env);
void	bi_pwd(void);
void	bi_cd(t_dllist *env, char *arg);

#endif