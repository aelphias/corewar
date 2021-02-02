/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:37:23 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 20:48:37 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		op_lfork(t_car *car, uint8_t *arena)
{
	int		arg;
	int		new_adr;

	arg = 0;
	new_adr = 0;
	arg = get_arg(car, 1, arena);
	new_adr = car->pc + arg;
	make_new_car(car, new_adr);
	walk(car, 2);
	car->pc = car->pos;
}
