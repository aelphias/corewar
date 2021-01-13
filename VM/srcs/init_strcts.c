/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:29:10 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/13 17:01:39 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void init_vm(t_vm *vm, t_plr *plr)
{
	vm->dump = -1;
	vm->hd_plrs = plr;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->winner_id = plr_count(vm->hd_plrs);
	printf("######vm->winner_id=%d\n", vm->winner_id);
	}
