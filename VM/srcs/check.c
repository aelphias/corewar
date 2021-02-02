/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:36:33 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/26 16:49:47 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	check(t_vm *vm, t_car **head_car)
{
	vm->check_count++;
	vm->last_check_cycle = vm->cycles;
	bury_car(vm, head_car);
	if ((vm->lived >= NBR_LIVE) || (vm->check_count == MAX_CHECKS))
	{
		vm->cycles_to_die = vm->cycles_to_die - CYCLE_DELTA;
		vm->check_count = 0;
	}
	vm->lived = 0;
}
