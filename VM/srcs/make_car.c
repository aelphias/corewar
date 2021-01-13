/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_car.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:49:17 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/28 18:00:18 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// void	init_car(t_plr *plr, t_car **head, int pos, t_vm *)
void	init_car(t_plr *plr, t_car **head, int pos)
{
	t_car		*car;

	car = (t_car *)ft_memalloc(sizeof(t_car));
	car->reg[0] = -(plr->id);
	car->parent_car = plr->id;
	car->pos = pos;
	car->next = NULL;
	//car->live = 1;
	car->id = plr->id; // инициализацию вызываем в цикле для каждой каретки, id растет на единицу
	if (!(*head))
		*head = car;
	else
	{
		car->next = (*head);
		*head = car;
	}
}

t_car	*make_car(t_plr *plr, t_vm *vm)
{
	// создание структуры под каретки
	int				equalizer;
	unsigned int	count;
	int				tmp;
	t_car			*car;
	
	count = 0;
	equalizer = 0;
	car = NULL;
	vm->plr_count = plr_count(plr);
	vm->car_count = vm->plr_count;
	/* ПОЗИЦИЯ КАРЕТОК ПОДСЧЕТ 
	 */
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
