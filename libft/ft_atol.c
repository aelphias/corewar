/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:22:06 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/02 18:47:06 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_err(void)
{
	ft_putendl("Error");
	exit(-1);
}

long long		ft_atol(const char *str)
{
	int			i;
	long long	sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\f' \
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] >= '0' &&
		str[i + 1] <= '9')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		ft_err();
	return (res * sign);
}
