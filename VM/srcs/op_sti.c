/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:34:04 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/14 18:37:21 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		c_c_sti(int c)
{
	int	a1;
	int a2;
	int a3;

	a1 = bitmask_corr(1, c);
	a2 = bitmask_corr(2, c);
	a3 = bitmask_corr(3, c);
	if (a1 == 0)
		return (1);
	if (a2 == 0)
		return (1);
	if (a3 != 1 || a3 != 3)
		return (1);
	return (0);
}

void	op_sti(t_car *car, uint8_t *arena, t_vm **vm)
{
	int				i;
	t_vm			*vm1;
	int				size_tmp;
	unsigned int	j;
	int				k;

	vm1 = (*vm);
	size_tmp = get_size(arena, car->pos, car->dir_size_status);
	if (!(c_c_sti(get_map(arena, car->dir_size_status + 1))) &&
			(i = red_arg(arena, car->pos, 3)) != -1)
	{
		if (bit_mask(2, get_map(arena, car->dir_size_status + 1)) == 1)
		{
			//j = (short)(pc->arg[1] + pc->arg[2]);
			//set_bit(car->pos, car->dir_size_status + (j % IDX_MOD), arena, pc->arg[0]);
		}
		else
		{
			//k = (short)(pc->arg[1] + pc->arg[2]);
			//set_bit(pc, car->dir_size_status + (k % IDX_MOD), arena, pc->arg[0]);
		}
	}
}
