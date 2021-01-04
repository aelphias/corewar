/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/04 20:09:04 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int get_op_code(unsigned char *arena, t_car *car)
{
	int res;

	res = arena[car->position];
	return (res);
}


void    op_add(t_car *car, unsigned char *arena)
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

void operations(t_car *car, unsigned char *arena, t_op *op)
{
	int op_id;
	
	op_id = get_op_code(arena, car);
	
	printf("op_id = %d", op_id); //(*op)->op_id
/* 	if (op_id == 12)
		op_fork(head_car, n_car, arena); */
		
	if (op_id == 4)
		op_add(car, arena); // id car?
}


void	game(t_plr *plr, t_car **car, unsigned char *arena, t_vm *vm, t_op *op)
{
	t_car *tmp;
	
	tmp = (*car);
	while (tmp)
	{
		printf("\n <<<<<<<I'm car= %d >>>>>>>\n", tmp->id);
		operations(tmp, arena, op);
		printf("\n END=%d\n", arena[tmp->position]);
		tmp = tmp->next;
	}
}
