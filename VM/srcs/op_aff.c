/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:38:13 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/18 20:15:49 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_car *car, uint8_t *arena, t_vm *vm)
{
	int		arg;
	char	val;

	arg = 0;
	val = '\0';
	if (arena && car)
	{
		arg = get_arg(vm, car, 1, arena);
		val = car->reg[MINUS_ONE(arg)];
		ft_printf("Aff: %c\n", (char)val % 256);
		car->pos += 1;
	}
}
