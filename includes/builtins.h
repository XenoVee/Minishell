/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 11:30:09 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/08 13:49:20 by rmaes         ########   odam.nl         */
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
void	echo(char *str, char **envp, int mode);
void	env(char **envp);

#endif