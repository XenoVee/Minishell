/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprintf.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/28 14:30:55 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/12 17:13:04 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPRINTF_H
# define FT_SPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

char	*ft_sprintf(const char *content, ...);
int		ft_lartpen(const char *content);
int		ft_partlen(const char *s);
char	*ft_realc_strjoin(char *str1, char *str2);
char	*ft_joinlen(char *s, const char **content);
void	ft_joinnbr(int n);
char	*ft_joinstr(char *ret, char *s);
void	ft_joinnbr_unsigned(unsigned int n);
char	*ft_joinchar(char *ret, int c);
void	ft_joinhexadecimal(unsigned int x, int cap);
char	*ft_join_pointer(char *ret, unsigned long ptr);

#endif
