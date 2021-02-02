/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:34:20 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		fill(long long n, char *number, int len)
{
	if (n == 0)
		number[0] = '0';
	number[len--] = '\0';
	while (n > 0)
	{
		number[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

int			lengin(long long n)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(long long n)
{
	char	*number;
	int		mins;
	int		len;

	mins = 0;
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
	{
		mins = 1;
		n *= -1;
	}
	len = lengin(n);
	number = ft_strnew(len + mins);
	if (!number)
		return (NULL);
	if (mins == 1)
	{
		number[0] = '-';
		len++;
	}
	fill(n, number, len);
	return (number);
}
