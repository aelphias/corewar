/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:42:16 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 20:42:26 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		make_new_car(t_car *car, int new_adr)
{
	t_car	*copy_car;
	int		i;

	i = 0;
	copy_car = ft_memalloc(sizeof(t_car));
	copy_car->next = car->hd_cars;
	car->hd_cars = copy_car;
	copy_car->carry = car->carry;
	while (i < 16)
	{
		copy_car->reg[i] = car->reg[i];
		i++;
	}
	copy_car->last_live_cycle = car->last_live_cycle;
	copy_car->pos = new_adr;
	copy_car->pc = new_adr;
	copy_car->parent_car = car->id;
	ft_memdel((void**)&copy_car);
}

void		op_fork(t_car *car, uint8_t *arena)
{
	int		arg;
	int		new_adr;

	arg = 0;
	new_adr = 0;
	arg = get_arg(car, 1, arena);
	new_adr = car->pc + (arg % IDX_MOD);
	make_new_car(car, new_adr);
	walk(car, 2);
	car->pc = car->pos;
}
