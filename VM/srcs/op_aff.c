/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:38:13 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/17 17:09:24 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_car *car, uint8_t *arena, t_vm *vm)
{
	int arg;
	char vel;

	if (arena && car)
	{
		arg = get_arg(vm, car, 1, arena);
		vel = (char)car->reg[arg];
		ft_printf("Aff: %c\n", vel);
		car->pos += 1;
	}
}
