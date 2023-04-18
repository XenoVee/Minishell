/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/28 14:30:55 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/18 17:03:46 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *content, ...);
int		ft_partlen(const char *s, size_t start);
void	ft_putlen(const char *s, size_t len, size_t start, size_t *wrt);
void	ft_putnbr_count(int n, size_t *wrt);
void	ft_putstr_count(char *s, size_t *wrt);
void	ft_putnbr_unsigned_count(unsigned int n, size_t *wrt);
void	ft_putchar_count(int c, size_t *wrt);
void	ft_puthexadecimal_count(unsigned int x, int cap, size_t *wrt);
void	ft_pointer_count(unsigned long ptr, size_t *wrt);
void	ft_put_ptr_count(unsigned long x, size_t *wrt);

#endif
