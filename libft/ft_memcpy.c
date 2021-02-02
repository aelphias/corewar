/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:36:14 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/11 19:36:14 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dst2;

	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	i = 0;
	if (src == dst)
		return (dst);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst2);
}
