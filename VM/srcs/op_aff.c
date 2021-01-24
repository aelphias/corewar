/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:38:13 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/21 21:58:45 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_car *car, uint8_t *arena)
{
	int		arg;
	char	val;

	arg = 0;
	val = '\0';
	if (arena && car)
	{
		arg = get_arg(car, 1, arena);
		val = car->reg[MINUS_ONE(arg)];
		ft_printf("Aff: %c\n", (char)val % 256);
		car->pos += 1;
		car->pc = car->pos;
	}
}
