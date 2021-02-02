/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:21:59 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				nuls(char *sym)
{
	int	i;

	i = 0;
	while ((sym[i] == ' ') || (sym[i] == '\f') || (sym[i] == '\n') \
			|| (sym[i] == '\r') || (sym[i] == '\t') || (sym[i] == '\v'))
		i++;
	return (i);
}

int				mins(char *sym, int i)
{
	if (sym[i] == '-')
		return (-1);
	return (1);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	nmb;
	char		*sym;

	nmb = 0;
	sym = (char *)str;
	i = nuls(sym);
	minus = 1;
	if (sym[i] == '-' || sym[i] == '+')
	{
		minus = mins(sym, i);
		i++;
	}
	while (sym[i] >= '0' && sym[i] <= '9')
	{
		nmb = nmb * 10 + ((int)sym[i] - 48);
		if ((nmb * 10 + ((int)sym[i] - 48)) / 10 != nmb)
			return (minus < 0) ? 0 : -1;
		i++;
	}
	return (minus * nmb);
}
