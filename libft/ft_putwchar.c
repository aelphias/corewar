/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:26:49 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/21 17:26:50 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar(unsigned wc, int wlen)
{
	int nb_bytes;

	if ((nb_bytes = ft_wcharlens(wc)) <= wlen)
	{
		if (nb_bytes == 1)
			ft_putchar(wc);
		else
		{
			if (nb_bytes == 2)
				ft_putchar(((wc & (0x1f << 6)) >> 6) + 0xC0);
			else if (nb_bytes == 3)
			{
				ft_putchar(((wc & (0xf << 12)) >> 12) + 0xE0);
				ft_putchar(((wc & (0x3f << 6)) >> 6) + 0x80);
			}
			else
			{
				ft_putchar(((wc & (0x7 << 18)) >> 18) + 0xF0);
				ft_putchar(((wc & (0x3f << 12)) >> 12) + 0x80);
				ft_putchar(((wc & (0x3f << 6)) >> 6) + 0x80);
			}
			ft_putchar(((wc & 0x3f)) + 0x80);
		}
	}
	return ((nb_bytes <= wlen) ? nb_bytes : 0);
}
