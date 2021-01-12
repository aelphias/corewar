/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:32:30 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/10 19:38:46 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_car *car, uint8_t *arena)
{
	int type_arg;
	int arg1;
	
	car->position = update_pos(car->position);
	type_arg = arena[update_pos(car->position + 1)];
	arg1 = car->dir_size_status;
	
}
