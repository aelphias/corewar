/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:24:48 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/14 18:46:09 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_plr		*get_playersid(t_plr *plrs, int plid)
{
	t_plr *p;

	if (plrs)
	{
		p = plrs;
		while (p)
		{
			if (p->id == plid)
				return (p);
			p = p->next;
		}
	}
	return (NULL); 
}

void	op_live(t_car *car, uint8_t *arena, t_vm *vm)
{
	int			cur_plr_n;
	t_plr		*plr;
	int			shift;

	/* cur_plr_n = 0;
	plr = NULL;
	printf("------>op_live() move=%d\n", car->move);
	if (vm && car && arena) 
	{	
		shift = move(car);
		printf("------>op_live()\n");
		car->last_live_cycle = vm->cycles;
		vm->lived++;
		//cur_plr_n = get_arg(vm, car, 1, arena);
		// дописать проверку то id игрока существует
		//vm->winner_id = -(cur_plr_n);
		
		if (cur_plr_n <= -1 && cur_plr_n >= -(MAX_PLAYERS)) 
		{
			plr = find_plr(vm->hd_plrs, cur_plr_n);
			printf("{   7   }\n");`
			vm->winner_id = plr->id;
			printf("{   8   }\n");
			printf("{   9   }\n");
		}
		car->pos += shift;
	} */
}


/* 

			printf("------>op_live()=== car->arg_type[0]=%d\n", car->arg_type[0]);

	ft_printf("CAR->REG %d \t\t N_PLR %d \n", car->reg[0], n_plr);

				ft_printf("A process shows that player %d ( %s ) is alive\n",plr->id, );

void	op_live(t_car *car, uint8_t *arena, t_vm *vm)
		printf("------>op_live() arg=%d\n", n_plr);
{
	
	t_vm **vm;
	t_plr *plr;
	
	ft_printf("----I'm op_live():\n");
	int a1;
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

*/
