/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:32:30 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 14:59:50 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	op_zjmp(t_car *car, uint8_t *arena)
{
	int arg;

	arg = 0;
	if (car->carry == 1)
	{
		arg = get_arg(car, 1, arena);
		car->pos = update_pos((car->pc + arg % IDX_MOD));
	}
	else
		walk(car, 2);
	car->pc = car->pos;
}
