/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:57:45 by qweissna          #+#    #+#             */
/*   Updated: 2018/12/22 21:57:40 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			lcp;
	unsigned char	a;

	lcp = 0;
	a = (unsigned char)c;
	str = (unsigned char *)b;
	while (lcp < len)
	{
		str[lcp] = a;
		lcp++;
	}
	return (str);
}
