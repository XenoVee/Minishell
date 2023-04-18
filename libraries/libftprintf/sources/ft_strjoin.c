/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strjoin.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rmaes <rmaes@student.codam.nl>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/17 16:42:11 by rmaes			 #+#	#+#			 */
/*   Updated: 2022/03/29 17:21:03 by rmaes			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static char	*bad_input(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (s1 && !s2)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;
	char			*str;

	if (!s1 || !s2)
		return (bad_input(s1, s2));
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len1 || i < len2)
	{
		if (i < len1)
			str[i] = s1[i];
		if (i < len2)
			str[len1 + i] = s2[i];
		i++;
	}
	str[len1 + len2] = '\0';
	return (str);
}
