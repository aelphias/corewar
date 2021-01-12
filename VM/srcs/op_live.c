/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:24:48 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/12 19:45:27 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_car *car, uint8_t *arena, t_vm *vm)
{

	int arg;

	arg = 0;
	if (vm && car && arena) 
	{
		car->last_live_cycle = vm->cycles;
		car->position++;
		arg = get_byte(arena, car->position);
		printf("------>op_live() arg=%d\n",arg);
	}
}
/* void	op_live(t_car *car, uint8_t *arena, t_vm *vm)
{
	t_vm **vm;
	t_plr *plr;
	
	ft_printf("----I'm op_live():\n");
	int arg1;
	car->dir_size_status = car->dir_size_status;

	 if (car && arena)
	{
		car->last_live_cycle = (*vm)->cycles;
		(*vm)->lived++;
		if (plr == get_playersid((*vm)->plr_count, get_byte(arena, -1)))
			{
				(*vm)->winner = plr->id;
				ft_printf("A process shows that player %d ( %s ) is alive\n",
					plr->id, plr->name);
			}
	}
	 
}

t_plr		*get_playersid(t_plr **plrs, uint8_t plid)
{
	t_plr *p;

	if (plrs)
	{
		p = *plrs;
		while (p)
		{
			if (p->id == plid)
				return (p);
			p = p->next;
		}
	}
	return (NULL); */
