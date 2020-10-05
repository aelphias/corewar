/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:16:59 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/10/24 19:17:00 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_ulltoa_base(unsigned long long dgt, int base)
{
	unsigned long long	temp;
	int					i;
	char				*retn;

	i = 0;
	if (base < 2 && base > 16)
		return (NULL);
	if (!dgt)
		return (ft_strdup("0"));
	temp = dgt;
	while (temp)
	{
		temp /= base;
		i++;
	}
	retn = (char*)malloc(i + 1);
	retn[i] = '\0';
	while (dgt)
	{
		temp = dgt % base;
		retn[--i] = (temp > 9) ? (temp - 10) + 'a' : temp + '0';
		dgt /= base;
	}
	return (retn);
}
