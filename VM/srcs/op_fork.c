/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:42:16 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/24 13:17:34 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void push_new_car(t_car **head, t_car *car, int new_adr)
{
	t_car *copy_car;
	int i;

	i = 0;
	copy_car = ft_memalloc(sizeof(t_car));
	copy_car->next = *head;
	*head = copy_car;

	copy_car->carry = car->carry;
	while (i < 16)
	{
		copy_car->reg[i] = car->reg[i];
		i++;
	}
	copy_car->last_live_cycle = car->last_live_cycle;
	copy_car->pos = new_adr;
}

void	op_fork(t_car *car, uint8_t *arena)
{
	int arg;
	int new_adr;

	arg = get_arg(car, 1, arena);
	new_adr = car->pos + (arg % IDX_MOD);
	push_new_car(&(car->hd_cars), car, new_adr);
	if (car->dir_size_status == 4)
		car->pos += 4;
	if (car->dir_size_status == 2)
			car->pos += 2;
	car->pc = car->pos;
}
