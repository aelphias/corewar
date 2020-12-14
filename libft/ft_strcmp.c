/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:59:01 by qweissna          #+#    #+#             */
/*   Updated: 2018/12/27 21:25:06 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	i = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (s1c[i] != '\0' && s2c[i] != '\0')
	{
		if (s1c[i] - s2c[i] != 0)
			return (s1c[i] - s2c[i]);
		i++;
	}
	if (s1c[i] == '\0' && s2c[i] == '\0')
		return (0);
	return (s1c[i] - s2c[i]);
}
