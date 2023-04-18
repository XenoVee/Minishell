/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/28 14:43:03 by rmaes         #+#    #+#                 */
/*   Updated: 2022/12/12 17:33:39 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>

// static void	conversion2(const char *content, char *ret, va_list ptr)
// {
	// if (content[0][0] == 'u')
	// 	ft_joinnbr_unsigned(va_arg(ptr, unsigned int));
	// else if (content[0][0] == 'x')
	// 	ft_joinhexadecimal((va_arg(ptr, int)), 0);
	// else if (content[0][0] == 'X')
	// 	ft_joinhexadecimal((va_arg(ptr, int)), 1);
// }
	// else if (content[0][0] == '%')
		// DONT FORGOR TO ADD THIS

static char	*conversion(const char **content, char *ret, va_list ptr)
{
	content[0]++;
	if (content[0][0] == 'c')
		ret = ft_joinchar(ret, va_arg(ptr, int));
	else if (content[0][0] == 's')
		ret = ft_joinstr(ret, va_arg(ptr, char *));
	else if (content[0][0] == 'p')
		ret = ft_join_pointer(ret, va_arg(ptr, unsigned long long));
	// else if (content[0][0] == 'd' || content[0][0] == 'i')
	// 	ft_joinnbr(va_arg(ptr, int));
	// else if (content[0][0] == '\0')
	// 	return (-1);
	// else
	// 	conversion2(content, len, ptr);
	// return (len + 1);
	content[0]++;
	return (ret);
}

char	*ft_sprintf(const char *content, ...)
{
	va_list	ptr;
	char	*ret;

	va_start(ptr, content);
	ret = ft_calloc(1, 1);
	while (content[0])
	{
		ret = ft_joinlen(ret, &content);
		if (content[0] == '%')
			ret = conversion(&content, ret, ptr);
		if (ret == NULL)
			return (0);
	}
	va_end(ptr);
	return (ret);
}

int	main(void)
{
	// ft_printf("\nHI %s", ft_sprintf("%p\n", ip));
	ft_printf("HI a %c a", 'i');
}
