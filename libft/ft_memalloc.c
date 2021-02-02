/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:36:21 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/11 19:36:21 by gjigglyp         ###   ########.fr       */
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
