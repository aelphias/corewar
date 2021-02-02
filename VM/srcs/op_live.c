/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:24:48 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 17:38:18 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		announce_leader(t_plr *plr)
{
	ft_printf("A process shows that player %s is alive\n", (plr->name));
}

t_plr		*check_node_existance(t_vm *vm, int player)
{
	t_plr	*plr;

	plr = vm->hd_plrs;
	while (plr)
	{
		if (plr->id == -player)
			return (plr);
		plr = plr->next;
	}
	return (NULL);
}

void		op_live(t_car *car, uint8_t *arena, t_vm *vm)
{
	int		cur_plr_n;
	t_plr	*plr;

	cur_plr_n = 0;
	plr = NULL;
	if (vm && car && arena)
	{
		car->last_live_cycle = vm->cycles;
		vm->lived++;
		cur_plr_n = get_arg(car, 1, arena);
		if ((plr = check_node_existance(vm, cur_plr_n)))
		{
			vm->winner_id = -cur_plr_n;
			announce_leader(plr);
		}
	}
	car->pos = update_pos(car->pos + move(car));
	car->pc = car->pos;
}
