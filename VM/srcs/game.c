/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/02 16:46:55 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_car	*clone_car(t_car *src, int id)
{
	int i;
	t_car *dst;
	
	if (src)
	{
		if (!(dst = (t_car*)ft_memalloc(sizeof(t_car))))
			print_error(ERR_MALLOC);
		while (src != NULL)
		{
			if (src->id == id)
			{
				dst->carry = src->carry;
				while (++i < 16)
					dst->reg[i] = src->reg[i];
				dst->live = src->live;
				dst->id = src->id;
				dst->parent_car = src->parent_car;
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


void	game(t_plr *plr, t_car *car, unsigned int *arena, t_vm *vm, t_op *op)
{
	int id = 1;
	forkk(car, arena, id);
	//print_list_car(car);
}
