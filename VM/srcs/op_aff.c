/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:38:13 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/13 20:58:02 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_car *car, uint8_t *arena, t_vm *vm)
{
	int ch;

	ch = 0;
	if (arena && car)
	{
		ch = car->reg[get_byte(arena, car->pos)];
		ft_printf("Aff: %c\n", (char)ch);
		car->pos += 1;
	}
}
