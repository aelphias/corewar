/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:30:25 by denis             #+#    #+#             */
/*   Updated: 2020/10/04 22:30:50 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_number(unsigned char *s, int size)
{
	int			i;
	unsigned	tmp;
	int			res;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		tmp = tmp << 8;
		tmp |= s[i];
		i++;
	}
	if (size == 1)
		res = (char)tmp;
	else if (size == 2)
		res = (short)tmp;
	else
		res = (int)tmp;
	return (res);
}
