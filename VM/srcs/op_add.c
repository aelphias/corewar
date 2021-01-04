/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:13:35 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/04 20:35:43 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

/* 
* Opcode 4. Take three registries, add the first two, 
* and place the result in thethird, right before modifying the carry.
*/

void	op_add(t_car *car, unsigned char *arena)
{
    int type_arg;
	int arg1;
	int arg2;
	int arg3;

	type_arg = arena[car->position + 1];
	arg1 = car->reg[arena[car->position + 2]];
	arg2 = car->reg[arena[car->position + 3]];
	car->reg[arena[car->position + 4]] = arg1 + arg2;
	printf("\n type_arg %d\n", type_arg);
	printf("\n type_arg %d\n", arg1);
	printf("\n type_arg %d\n", arg2);
	printf("\n car->reg[arena[car->position + 4]] %d\n", car->reg[arena[car->position + 4]]);
	car->position += 5;
//	printf("\n +=5 =%d\n", arena[car->position]);
	
}
