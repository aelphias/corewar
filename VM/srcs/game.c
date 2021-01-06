/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/06 15:25:31 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_func(void (**f)(t_car *, uint8_t*))
{
	f[0] = NULL;
	f[4] = &op_add;
	//f[12] = &op_fork;
}

int	get_op_code(uint8_t *arena, t_car *car)
{
	int res;

	res = arena[car->position];
	return (res);
}

void	operations(t_car *car, uint8_t *arena, void (**func)(t_car *, uint8_t *))
{
	//int op_id;
	car->op_id = get_op_code(arena, car);
	func[car->op_id](car, arena);
	//printf("op_id = %d", car->op_id); //(*op)->op_id
/* 	if (op_id == 12)
		op_fork(head_car, n_car, arena); */
		
/* 	if (op_id == 4)
		op_add(car, arena); // id car? */
}

/* 
* 0. Будем играть пока живы каретки
*/
void	game(t_plr *plr, t_car **head_car, uint8_t *arena, t_vm *vm)
{
	void	(*func[17])(t_car *, uint8_t *);
	t_car	*tmp;
	
	init_func(func);
	tmp = (*head_car);
	
	while (*head_car)
	{
		while (tmp)  // играть пока живы каретки и ??
		{
			operations(tmp, arena, func);
			tmp = tmp->next;
		}
		tmp = (*head_car);
	}
}
