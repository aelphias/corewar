/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_car.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:49:17 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 13:42:55 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		init_car(t_plr *plr, t_car **head, int pos)
{
	t_car	*car;

	car = (t_car *)ft_memalloc(sizeof(t_car));
	car->reg[0] = -(plr->id);
	car->pos = pos;
	car->pc = car->pos;
	car->next = NULL;
	car->id = plr->id;
	if (!(*head))
		*head = car;
	else
	{
		car->next = (*head);
		*head = car;
	}
	car->hd_cars = (*head);
}

t_car		*make_car(t_plr *plr, t_vm *vm)
{
	int		equalizer;
	int		count;
	int		tmp;
	t_car	*car;

	count = 0;
	equalizer = 0;
	car = NULL;
	vm->car_count = vm->plr_count;
	if ((vm->plr_count % 2) != 0)
		equalizer = -1;
	while (count < vm->plr_count)
	{
		tmp = (count * ((MEM_SIZE + equalizer) / vm->plr_count));
		plr->pos = tmp;
		init_car(plr, &car, tmp);
		plr = plr->next;
		count++;
	}
	return (car);
}
