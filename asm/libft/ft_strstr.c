/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:43:58 by qweissna          #+#    #+#             */
/*   Updated: 2018/12/08 22:47:41 by qweissna         ###   ########.fr       */
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
