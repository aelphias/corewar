/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/02 21:49:28 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/* 

void clone_car (t_car *head, int id)
{
	int i;

	i = -1;
	tmp = head;
	if (head)
	{
		if (!(dst = (t_car*)ft_memalloc(sizeof(t_car))))
			print_error(ERR_MALLOC);
		while (src != NULL)
		{
			if (src->id == id)
			{
				dst->carry = src->carry;
				while (++i < 16)
					new->reg[i] = tmp->reg[i];
				new->live = tmp->live;
				new->id = tmp->id;
				new->parent_car = tmp->parent_car;
			}
			src = src->next;
		}
		dst->next = src;
		src = dst;
	}
	return (src);
}
 */

// void	forkk(t_car **head, t_car *n_car, unsigned int *arena)
// {
// /* 	t_car *new_car;
	
// 	 int pos;
// 	 */
// 	printf("hi I'm fork! ;)\n");
	
	
	
// }

// void operations(t_plr *plr, t_car **head_car, unsigned int *arena, int op_id)
// {
// 	t_car *n_car; // энный элемент промежуточный
	 	
// 	n_car = (*head_car);
// 	if (op_id == 12)
// 		forkk(head_car, n_car, arena);
// 	if (op_id == 4)
// 		add(head_car, arena); // id car?
// }



// void	game(t_plr *plr, t_car *car, unsigned int *arena, t_vm *vm, t_op *op)
// {
// 	op = (t_op*)ft_memalloc(sizeof(t_op));
// 	op->op_id = 12;
// 	// 1. f() которая работает с операциями
// 	operations(plr, &car, arena, op->op_id);
// 	//forkk(car, arena, id);
// }
