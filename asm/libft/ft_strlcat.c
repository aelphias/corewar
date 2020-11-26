/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:47:38 by qweissna          #+#    #+#             */
/*   Updated: 2018/12/07 23:53:40 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	char	*src_cp;

	i = 0;
	src_cp = (char *)src;
	while (dst[i])
		i++;
	len = i;
	if (size < i)
		return (ft_strlen(src) + size);
	size -= i;
	while (size > 1 && *src_cp)
	{
		dst[i++] = *src_cp++;
		size--;
	}
	dst[i] = '\0';
	return (len + ft_strlen(src));
}
