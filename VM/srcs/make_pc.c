/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:49:17 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/27 18:48:42 by aelphias         ###   ########.fr       */
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

t_vm	*make_pc(t_vm *vm, t_plr *plr)
{
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		print_error(ERR_MALLOC);
	//plr_position(plr);
	vm->nop = plr_count(plr);
	ft_printf("nop%d\n", vm->nop);
}
