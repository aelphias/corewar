/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:14:14 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/12 17:47:29 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void					op_st(t_car *car, uint8_t *arena)
{
	int p;
	int val1;
	int val2;
	t_vm	*vm;

	if (arena && car)
	{
		val2 = car->pc + sizeof(t_op) + sizeof(t_arg_type);
		if (car->arg[1] = REG_CODE)
		{
			//val1 = car->reg[byteread((arena, val2 + get_size_arg(car->)))];
		}
		else
		{
			//p = car->pc + ( % IDX_MOD);
		}
		//car->reg[] = val1;
	}
}

char				byteread(unsigned char *a, unsigned int posit)
{
	while (posit >= MEM_SIZE)
		posit = posit - MEM_SIZE;
	return (a[posit]);
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
	short			bytes[sizeof(int)];

	i = 0;
	while (i < sizeof(int))
	{
		bytes[i] = byteread(a, posit + i);
		i++;
	}
	return ((bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3]);
}