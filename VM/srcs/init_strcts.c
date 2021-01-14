/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:29:10 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/14 13:26:15 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void init_vm(t_vm *vm)
{	
	ft_bzero(vm, sizeof(t_vm));
	vm->dump = -1;
}

void init_plr(t_vm *vm, t_plr *plr)
{
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->hd_plrs = plr;
	vm->winner_id = plr_count(vm->hd_plrs);
	vm->plr_count = plr_count(vm->hd_plrs);
	printf("######vm->winner_id=%d\n", vm->winner_id);
}
