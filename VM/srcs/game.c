/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/04 17:59:21 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int get_op_code(unsigned char *arena, t_car *car)
{
	int res;

	res = 0;
	res = arena[car->position];
	return (res);
}


void    op_add(t_car *car, unsigned char *arena)
{
    int type_arg;
	int arg1;
	int arg2;
	int arg3;

	type_arg = 0;
	arg1 = 0;
	arg2 = 0;
	arg3 = 0;
	
	type_arg = arena[car->position + 1];
	arg1 = arena[car->position + 2];
	arg2 = arena[car->position + 3];
    arg3 = arena[car->position + 4];
	
    printf("\n type_arg %d\n", type_arg);
	printf("\n type_arg %d\n", arg1);
	printf("\n type_arg %d\n", arg2);
	printf("\n type_arg %d\n", arg3);
}

void operations(t_plr *plr, t_car *head_car, unsigned char *arena, t_op **op)
{
	//t_car *n_car; // энный элемент промежуточный
	int op_id = 0;
	//(*op)->op_id 
	
	op_id = get_op_code(arena, head_car);
	
	printf("op_id = %d", op_id); //(*op)->op_id
/* 	if (op_id == 12)
		op_fork(head_car, n_car, arena); */
		
	if (op_id == 4)
		op_add(head_car, arena); // id car?
}


void	game(t_plr *plr, t_car *car, unsigned char *arena, t_vm *vm, t_op **op)
{
	//op->op_id = 12;
	operations(plr, car, arena, op);
}
