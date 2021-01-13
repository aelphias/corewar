/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:29:10 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/13 18:54:30 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void init_vm(t_vm *vm)
{
	vm->dump = -1;
}

void init_plr(t_vm *vm, t_plr *plr)
{
	vm->hd_plrs = plr;
	vm->cycles_to_die = CYCLE_TO_DIE;
	printf("######vm->winner_id=%d\n", vm->winner_id);
	vm->winner_id = plr_count(vm->hd_plrs);
}
