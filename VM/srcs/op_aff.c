/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:38:13 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/24 17:13:55 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_car *car, uint8_t *arena)
{
	int		arg;
	char	val;
	int		num;

	arg = 0;
	val = 48;
	if (arena && car)
	{
		arg = get_arg(car, 1, arena);
		num = car->reg[MINUS_ONE(arg)];
		val = num + '0';
		ft_printf("Aff: %d\n", val);
		car->pos += 1;
		car->pc = car->pos;
	}
}
