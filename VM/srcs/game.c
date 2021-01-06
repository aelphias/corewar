/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/06 19:53:44 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/* void	init_func(void (**f)(t_car *, uint8_t*))
{
	f[0] = NULL;
	f[4] = &op_add;
	//f[12] = &op_fork;
}

int	get_op_code(uint8_t *arena, t_car *car)
{
	return (arena[car->position]);
}

void	operations(t_car *car, uint8_t *arena, void (**func)(t_car *, uint8_t *))
{
	printf("operation id is %d", car->op_code);
	func[car->op_code](car, arena);
}

void	cycle(t_car **head_car, uint8_t *arena)
{
	t_car	*car;
	void	(*func[17])(t_car *, uint8_t *);
	
	init_func(func);
	while (*head_car)
	{
		while (car)  // играть пока живы каретки и ??
		{
			if (car->wait == 0)
				get_op_code(arena, car);
			if (car->op_code >= 1 && car->op_code <= 16 )
			{
			}
						
			operations(car, arena, func);
			car = car->next;
		}
		car = (*head_car);
	}
}



void	game(t_plr *plr, t_car **head_car, uint8_t *arena, t_vm *vm)
{
	t_car	*car;
	
	car = (*head_car);
	while (vm->num_car)
	{
		//cycle(head_car, )
		if (!vm->cycles_to_die || (vm->cycles % vm->cycles_to_die) == 0)
			check(vm);		
	}
}
 */