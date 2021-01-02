/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/02 18:21:45 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

void	forkk(t_car *head, unsigned int *arena, int id)
{
	int i;
	t_car *new_list;
	
	i = 0;
	head = new_list = clone_car(head, id);
	ft_printf("\n\n");
	while (head != NULL) 
	{
		ft_printf("id = %d\n", head->id);
		printf("code = ");
		while (i < 16)
		{
			printf("%x ", head->reg[i]);
			i++;
		}
		head = head->next;
	}
}

void	forkk(t_car *head, unsigned int *arena, int id)
{
	clone_car (head, id);
}


void	game(t_plr *plr, t_car *car, unsigned int *arena, t_vm *vm, t_op *op)
{
	int id = 1;
	forkk(car, arena, id);
	//print_list_car(car);
}
