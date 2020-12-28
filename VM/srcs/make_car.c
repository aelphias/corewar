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

void	plr_position(t_plr *plr)
{
	int plr_amount;
	int equalizer;
	int count;
	
	equalizer = 0;
	plr_amount = plr_count(plr);
	if (plr_amount / 2 != 0)
		equalizer = -1;
	while (count < plr_amount)
	{
		plr->position =  (count * (MEM_SIZE / plr_amount) + equalizer);
		count++;
	}
	
}

t_car	*make_car(t_plr *plr, t_vm *vm)
{
	// создаваться структ под каретки
	int i;
	t_car *car;
	
	if (!(car = (t_car *)ft_memalloc(sizeof(t_car))))
		return (NULL);
	//plr_position(plr);
	vm->num_plr = plr_count(plr);
	//i = vm->num_plr;
}
