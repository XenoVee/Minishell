/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 11:30:09 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/19 15:41:45 by rmaes         ########   odam.nl         */
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

enum e_cpyiter
{
	OG = 0,
	CPY,
	CHAR,
};

/*functions*/
void	bi_echo(char *str, t_dllist *env, int mode);
void	bi_env(t_dllist *env);
void	bi_unset(char *var, t_dllist *env);
void	bi_export(char *var, t_dllist *env);

#endif