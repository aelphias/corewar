/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:24:48 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/16 21:41:34 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

bool	check_node_existance(t_vm *vm, int	player)
{
	t_plr *plr;

	plr = vm->hd_plrs;
	while (plr)
	{
		if (plr->id == -player)
			return(true);
		plr = plr->next;
	}
	return(false);	
}

void	op_live(t_car *car, uint8_t *arena, t_vm *vm)
{
	int			cur_plr_n;
	t_plr		*plr;
	int			shift;

	cur_plr_n = 0;
	plr = NULL;
	shift = 0;
	if (vm && car && arena) 
	{	
		car->last_live_cycle = vm->cycles;
		vm->lived++;
		cur_plr_n = get_arg(vm, car, 1, arena);
		if (check_node_existance(vm, cur_plr_n)) 
			vm->winner_id = -cur_plr_n;
	}
	shift = move(car);
	car->pos += shift;
}
