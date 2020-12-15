/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:27:43 by jigglyp           #+#    #+#             */
/*   Updated: 2020/12/15 16:05:47 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*begin;

	i = 0;
	j = 0;
	begin = haystack;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		while (*begin++ == needle[i] && needle[i] && len >= j)
		{
			i++;
			j++;
		}
		if (needle[i] == '\0')
			return ((char*)(haystack));
		i = 0;
		j = 0;
		begin = ++haystack;
		len--;
	}
	return (0);
}
