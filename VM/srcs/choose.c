/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:04:07 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/30 13:50:20 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	choose_1(t_car *car, uint8_t *arena)
{
	if (car->op_code == 2)
		op_ld(car, arena);
	else if (car->op_code == 3)
		op_st(car, arena);
	else if (car->op_code == 4)
		op_add(car, arena);
	else if (car->op_code == 5)
		op_sub(car, arena);
	else if (car->op_code == 6)
		op_and(car, arena);
	else if (car->op_code == 7)
		op_or(car, arena);
	else if (car->op_code == 8)
		op_xor(car, arena);
	else if (car->op_code == 9)
		op_zjmp(car, arena);
	else if (car->op_code == 10)
		op_ldi(car, arena);
	else if (car->op_code == 11)
		op_sti(car, arena);
	else if (car->op_code == 12)
		op_fork(car, arena);
	else
		choose_2(car, arena);
}

void	choose_2(t_car *car, uint8_t *arena)
{
	if (car->op_code == 13)
		op_lld(car, arena);
	else if (car->op_code == 14)
		op_lldi(car, arena);
	else if (car->op_code == 15)
		op_lfork(car, arena);
	else if (car->op_code == 16)
		op_aff(car, arena);
	else
		return ;
}
