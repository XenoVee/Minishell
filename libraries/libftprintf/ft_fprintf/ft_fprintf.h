/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fprintf.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/28 14:30:55 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/29 15:26:21 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_fprintf(int fd, const char *content, ...);
int		ft_fpartlen(const char *s, size_t start);
void	ft_fputlen(const char *s, size_t len, size_t start, size_t *wrt);
void	ft_fputnbr_count(int n, size_t *wrt);
void	ft_fputstr_count(char *s, size_t *wrt);
void	ft_fputnbr_unsigned_count(unsigned int n, size_t *wrt);
void	ft_fputchar_count(int c, size_t *wrt);
void	ft_fputhexadecimal_count(unsigned int x, int cap, size_t *wrt);
void	ft_fpointer_count(unsigned long ptr, size_t *wrt);
void	ft_fput_ptr_count(unsigned long x, size_t *wrt);

#endif
