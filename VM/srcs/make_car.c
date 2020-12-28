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

void	init_car(t_plr *plr, t_car **head, int pos, t_vm *vm)
{
	int			i;
	t_car		*car;

	i = 0;
	car = (t_car *)ft_memalloc(sizeof(t_car));
	ft_bzero(car, sizeof(t_car));

	i = -1;
	while (++i < 3)
		car->arg[i] = 0;
	car->reg[0] = plr->id;
	//init_pc2(pc, r);
	car->parent_car = plr->id;
	car->position = pos;
	car->next = NULL;
	if (!(*head))
		*head = car;
	else
	{
		car->next = (*head);
		*head = car;
	}
	ft_printf("car%d\n", car->parent_car);
}

t_car	*make_car(t_plr *plr, t_vm *vm)
{
	// создаваться структ под каретки
	int		equalizer;
	int		count;
	int		tmp;
	t_car	*car;
	
	equalizer = 0;
	count = 0;
	car = NULL;
	vm->num_plr = plr_count(plr);
	if (vm->num_plr / 2 != 0)
		equalizer = -1;
	while (count++ < vm->num_plr)
	{
		tmp = (count * ((MEM_SIZE + equalizer) / vm->num_plr));
		plr->position = tmp;
		init_car(plr, &car, tmp, vm);
		plr = plr->next;
	}
	return (car);
	/* if (!(car = (t_car *)ft_memalloc(sizeof(t_car))))
		return (NULL); */
	//i = vm->num_plr;
}
