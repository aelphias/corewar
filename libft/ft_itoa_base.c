/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:03:00 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_s(long long nb, int base)
{
	int		c;

	c = 0;
	while (nb > 0)
	{
		nb /= base;
		c += 1;
	}
	return (c);
}

char		convert(int d, int l)
{
	if (d >= 0 && d <= 9)
		return (d + '0');
	if (d >= 10 && d <= 16)
	{
		if (l == 0)
			return ('a' + d - 10);
		else
			return ('A' + d - 10);
	}
	return (0);
}

char		*ft_itoa_base(long long nb, int base, int l)
{
	char	*res;
	int		len;

	if (nb <= 0)
		return (ft_strdup("0"));
	len = get_s(nb, base);
	res = ft_strnew(len);
	if (!res)
		return (0);
	res[len] = '\0';
	while (nb != 0)
	{
		len--;
		res[len] = convert((nb % base), l);
		nb /= base;
	}
	return (res);
}
