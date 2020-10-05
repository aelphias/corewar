/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 08:47:37 by denis             #+#    #+#             */
/*   Updated: 2020/10/05 08:47:38 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	*ft_memdup(const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*tmp;

	if (src == NULL || n == 0)
		return (0);
	dst = (unsigned char*)malloc(n);
	tmp = (unsigned char*)src;
	while (n > 0)
	{
		n--;
		dst[n] = tmp[n];
	}
	return (dst);
}