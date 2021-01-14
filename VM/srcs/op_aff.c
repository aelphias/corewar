/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:38:13 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/14 21:20:20 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			if_aff(int c)
{
	int		arg1;

	arg1 = bitmask_corr(1, c);
	if (arg1 != 1)
		return (1);
	return (0);
}

void	op_aff(t_car *car, uint8_t *arena, t_vm *vm)
{
	int ch;

	if (arena && car)
	{
		ch = car->reg[MINUS_ONE(get_byte(arena, car->pos))];
		ft_printf("Aff: %c\n", (char)ch);
		car->pos += 1;
	}
}
