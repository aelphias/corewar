/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2020/12/31 18:42:13 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void clone_car (t_car *head, int id)
{
	t_car *new;
	t_car *tmp;
	int i;

	i = -1;
	tmp = head;
	if (head)
	{
		if (!(new = (t_car*)ft_memalloc(sizeof(t_car))))
			print_error(ERR_MALLOC);
		while (tmp != NULL)
		{
			if (tmp->id == id)
			{
				new->carry = tmp->carry;
				while (++i < 16)
					new->reg[i] = tmp->reg[i];
				new->live = tmp->live;
				new->id = tmp->id;
				new->parent_car = tmp->parent_car;
			}
			tmp = tmp->next;
		}
		new->next = head;
		head = new;
	}

	ft_printf("\n\n");
	while (head != NULL) 
	{
		ft_printf("id = %d\n", head->id);
		printf("reg = ");
		i = 0;
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
