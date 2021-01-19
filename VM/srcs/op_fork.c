/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:42:16 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/19 21:32:18 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


/*void clone_car (t_car *head, int id)
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
}*/

void push_start(t_car **head, int val)
{
	t_car *copy_car;
    copy_car = malloc(sizeof(t_car));
	//copy
    copy_car->next = *head;
    *head = copy_car;
}

void	op_fork(t_car *car, uint8_t *arena, t_vm *vm)
{

    // add 0 to start
    push_start(&car, 0);
 
    // print updated list
	//car_copy = a1 % IDX_MOD;
	//car_new = clone_car(car, );
	
}