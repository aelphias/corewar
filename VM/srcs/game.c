/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/07 22:21:02 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/* void	check(t_vm **vm, t_car **head_car)
{
	(*vm)->check_count++;
	bury_car(vm, head_car);
}
*/
void	init_func(void (**f)(t_car *, uint8_t*))
{
	f[0] = NULL;
	f[4] = &op_add;
	//f[12] = &op_fork;
}
 
void	exec(t_car *car, uint8_t *arena, t_op *op)
{
	printf("operation id is %d", car->op_code);
	//func[car->op_code](car, arena);
	car->wait = op[car->op_code].cycle_wait;
	if (car->wait)
		car->wait--;
	else
		op[car->op_code].func(car, arena);
}
/* 
Чтобы запустить цикл нужно:
init_car

 */

bool	valid_op(t_car *car)
{
	if (car->op_code >= 1 && car->op_code <= 16)
		return(true);
	return (false);
}

void	cycle(t_car **head_car, uint8_t *arena, t_op *op)
{
	t_car	*car;
	void	(*func[17])(t_car *, uint8_t *);
	
	car = (*head_car);
			car->op_code = get_op_code(arena, car->position);
			ft_printf("op_code= %x\n",car->op_code);
			ft_printf("car id=%d\n",car->id);
			//car->position++;
	/* init_func(func);
	while (car)
	{
		if (car->wait == 0)
		{
			get_op_code(arena, car->position);
			if (valid_op(car))
				exec(car, arena, op);
		}
		car = car->next;
	} */
}

void	game(t_plr *plr, t_car **head_car, uint8_t *arena, t_vm **vm, t_op *op)
{
	//while ((*vm)->car_count)
	//{
		//(*vm)->cycles++;
		//ft_printf("(*vm)->cycles = %d\n", (*vm)->cycles);
		
			ft_printf("head_car->position = %d\n", (*head_car)->position);
		cycle(head_car, arena, op);
		/* if (!((*vm)->cycles_to_die) ||
		 ((*vm)->cycles % (*vm)->cycles_to_die) == 0)
			check(vm, head_car); */
		//(*vm)->car_count--;
	//}
	//ft_printf("Contestant 1, %s has won !\n", (*vm)->winner);
	//			func[car->op_code](car, arena);
}
