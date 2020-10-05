/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:37:53 by qweissna          #+#    #+#             */
/*   Updated: 2018/12/22 22:03:11 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *str;

	str = 0;
	str = (unsigned char *)malloc(size * sizeof(unsigned char));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return ((void *)str);
}
