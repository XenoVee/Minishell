/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/28 14:43:03 by rmaes         #+#    #+#                 */
/*   Updated: 2023/06/29 15:32:30 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include <errno.h>
#include <string.h>

static void	varread2(const char *content, size_t len, size_t *wrt, va_list ptr)
{
	if (content[len] == 'u')
		ft_fputnbr_unsigned_count(va_arg(ptr, unsigned int), wrt);
	else if (content[len] == 'x')
		ft_fputhexadecimal_count((va_arg(ptr, int)), 0, wrt);
	else if (content[len] == 'X')
		ft_fputhexadecimal_count((va_arg(ptr, int)), 1, wrt);
	else if (content[len] == '%')
		wrt[0] += write(wrt[1], "%", 1);
}

static int	varread(const char *content, size_t len, size_t *wrt, va_list ptr)
{
	len++;
	if (content[len] == 'c')
		ft_fputchar_count(va_arg(ptr, int), wrt);
	else if (content[len] == 's')
		ft_fputstr_count(va_arg(ptr, char *), wrt);
	else if (content[len] == 'p')
		ft_fpointer_count(va_arg(ptr, unsigned long long), wrt);
	else if (content[len] == 'd' || content[len] == 'i')
		ft_fputnbr_count(va_arg(ptr, int), wrt);
	else if (content[len] == '\0')
		return (-1);
	else
		varread2(content, len, wrt, ptr);
	return (len + 1);
}

int	ft_fprintf(int fd, const char *content, ...)
{
	size_t	len;
	int		start;
	size_t	wrt[2];
	va_list	ptr;

	va_start(ptr, content);
	len = 0;
	start = 0;
	wrt[0] = 0;
	wrt[1] = fd;
	while (content[start])
	{
		len = ft_fpartlen(content, start);
		ft_fputlen(content, len, start, wrt);
		start = len;
		if (content[len] == '%')
			start = varread(content, len, wrt, ptr);
		if (start == -1)
			return (wrt[0]);
	}
	va_end(ptr);
	return (wrt[0]);
}
