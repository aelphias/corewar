/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:01:50 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/12 21:02:06 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char				byteread(unsigned char *a, unsigned int posit)
{
	while (posit >= MEM_SIZE)
		posit = posit - MEM_SIZE;
	return (a[posit]);
}

void				bytewrite(unsigned char byte, unsigned char *a, unsigned int posit)
{
	while (posit >= MEM_SIZE)
		posit = posit - MEM_SIZE;
	a[posit] = byte;
}

short				read16int(unsigned char *a, int posit)
{
	unsigned long	i;
	short			bytes[sizeof(short)];

	i = 0;
	while (i < sizeof(short))
	{
		bytes[i] = byteread(a, posit + i);
		i++;
	}
	return ((bytes[0] << 8) | bytes[1]);
}

int				read32int(unsigned char *a, int posit)
{
	unsigned long	i;
	int			bytes[sizeof(int)];

	i = 0;
	while (i < sizeof(int))
	{
		bytes[i] = byteread(a, posit + i);
		i++;
	}
	return ((bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3]);
}
