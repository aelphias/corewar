/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:54:22 by jigglyp           #+#    #+#             */
/*   Updated: 2020/12/15 16:02:40 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dc;
	const unsigned char	*sc;

	dc = (unsigned char *)dst;
	sc = (const unsigned char *)src;
	if (src == dst)
		return (dst);
	if (dc < sc)
	{
		while (len-- > 0)
			*dc++ = *sc++;
	}
	else
	{
		while (len-- > 0)
			*(dc + len) = *(sc + len);
	}
	return (dst);
}
