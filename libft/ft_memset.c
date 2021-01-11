/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:34:14 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/11 19:34:14 by gjigglyp         ###   ########.fr       */
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
