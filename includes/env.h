/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/25 14:18:11 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/25 14:30:50 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "../libraries/libftprintf/libft.h"
# include "../libraries/cdl_list/include/cdl_list.h"

t_dllist	*envcpy(char **envp);
int			envsearch(t_dllist *env, char *var);
char		*ft_getenv(t_dllist *env, char *var);
t_dlnode	*ft_getenvnode(t_dllist *env, char *var);

#endif