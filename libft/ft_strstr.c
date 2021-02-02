/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:27:09 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/11 19:27:10 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	const char	*begin;

	i = 0;
	begin = haystack;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		while (*begin++ == needle[i] && needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)(haystack));
		i = 0;
		begin = ++haystack;
	}
	return (0);
}
