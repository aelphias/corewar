/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:33:27 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/10 13:36:16 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ldi(t_car *car, uint8_t *arena, t_vm *vm)
{
	bool silence_make;
	if (arena && car)
	{
		silence_make = car->carry;
		
	}
}
