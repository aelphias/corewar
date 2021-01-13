/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:33:27 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/13 18:10:54 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ld_or_lld(int cd)
{
	int a1;
	int a2;

	a1 = bitmask_corr(1, cd);
	a2 = bitmask_corr(2, cd);
	if ((a1 != 2 && a2 !=3) || a2 != 1)
		return (1);
	return (0);
}

void		op_ldi(t_car *car, uint8_t *arena, t_vm *vm)
{
	int i;
	int tmp_size;
	int j;
	unsigned int temp;

	//tmp_size = get_size(vm->);

}
