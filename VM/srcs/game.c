/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/04 21:10:34 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_func(void (**f)(t_car *, unsigned char*))
{
	f[0] = NULL;
	f[4] = &op_add;
	//f[12] = &op_fork;
}

int get_op_code(unsigned char *arena, t_car *car)
{
	int res;

	res = arena[car->position];
	return (res);
}

void operations(t_car *car, unsigned char *arena, void (**func)(t_car *, unsigned char *))
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


void	game(t_plr *plr, t_car **car, unsigned char *arena, t_vm *vm)
{
	void		(*func[17])(t_car *, unsigned char *);
	t_car *tmp;
	
	init_func(func);
	tmp = (*car);
	while (tmp)
	{
		printf("\n <<<<<<<I'm car= %d >>>>>>>\n", tmp->id);
		operations(tmp, arena, func);
		printf("\n END=%d\n", arena[tmp->position]);
		tmp = tmp->next;
	}
}
