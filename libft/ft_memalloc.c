/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:37:53 by jigglyp           #+#    #+#             */
/*   Updated: 2020/12/15 16:02:15 by aelphias         ###   ########.fr       */
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
