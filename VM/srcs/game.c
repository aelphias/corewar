/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/10 13:44:09 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/* void	check(t_vm **vm, t_car **head_car)
{
	(*vm)->check_count++;
	bury_car(vm, head_car);
}
*/
/* void	init_func(void (**f)(t_car *, uint8_t*))
{
	f[0] = NULL;
	f[1] = &op_add;
	f[2] = &op_add;
	f[3] = &op_add;
	f[4] = &op_add;
	f[5] = &op_add;
	f[6] = &op_add;
	f[7] = &op_add;
	f[8] = &op_add;
	f[9] = &op_add;
	f[10] = &op_add;
	f[11] = &op_add;
 	f[12] = &op_fork;
	f[13] = &op_fork;
	f[14] = &op_fork;
	f[15] = &op_fork;
	f[16] = &op_fork;
*/

 
void	exec(t_car *car, uint8_t *arena)
{
	t_op *op;
	
	op = &g_op[MINUS_ONE(car->op_code)];
	car->wait = op->cycles_wait;
	car->wait = 0;
	if (car->wait)
		car->wait--;
	else  
		op->func(car, arena);
		//func[car->op_code](car, arena);
		//op[car->op_code].func(car, arena);
}
/* 
Чтобы запустить цикл нужно:
init_car
 */

bool	valid_op(t_car *car)
{
	if (car->op_code >= 1 && car->op_code <= 16)
		return (true);
	return (false);
}

void	cycle(t_car **head_car, uint8_t *arena)
{
	t_car	*car;
	
	car = (*head_car);
	//car->op_code = get_byte(arena, car->position);
/* 	if (valid_op(car))
		exec(car, arena, op); */
	//init_func(func);
	while (car)
	{
		if (car->wait == 0)
		{
			car->op_code = get_byte(arena, car->position);
			//get_args(arena, car, op);
			//if (type_of_args)
			//take args
			//move  car
			//car->position++;
			if (valid_op(car))
				exec(car, arena);
		}
		else
		car->wait--;
	car = car->next;
	}
}

void	game(t_car **head_car, uint8_t *arena, t_vm **vm)
{
	// while ((*vm)->car_count)
	//void	(*func[17])(t_car *, uint8_t *);
	//init_func(func);
	while ((*vm)->cycles < 11)
	{
		(*vm)->cycles++;
		cycle(head_car, arena);
		if (!((*vm)->cycles_to_die) || ((*vm)->cycles % (*vm)->cycles_to_die) == 0)
			printf("----{inside game()}--Check() was called\n");//check(vm, head_car);
	}
	ft_printf("(*vm)->cycles = %d\n", (*vm)->cycles);
	//ft_printf("Contestant 1, %s has won !\n", (*vm)->winner);
}
