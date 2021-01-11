/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:30:37 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/11 19:30:38 by gjigglyp         ###   ########.fr       */
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
