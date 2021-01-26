/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:37:23 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/24 13:00:46 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lfork(t_car *car, uint8_t *arena)
{
	int arg;
	int new_adr;

	new_adr = 0;
	arg = get_arg(car, 1, arena);
	new_adr = arg + car->pos;
	push_new_car(&(car->hd_cars), car, new_adr);
	if (car->dir_size_status == 4)
		car->pos += 4;
	if (car->dir_size_status == 2)
		car->pos += 2;
	car->pc = car->pos;
}
