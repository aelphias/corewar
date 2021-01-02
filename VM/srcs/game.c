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

void	forkk(t_car *head, unsigned int *arena)
{
	t_car *new;
	
	if (head)
	{
		if (!(new = (t_car*)ft_memalloc(sizeof(t_car))))
			print_error(ERR_MALLOC);
		new->next = head;
		head = new;
	}
	new->id = 2021;
	// printf("new=%d\n", new->id);

	while (head != NULL) 
	{
		ft_printf("id = %d\n", head->id);
		head = head->next;
	}
}


void	game(t_plr *plr, t_car *car, unsigned int *arena, t_vm *vm, t_op *op)
{
	print_list_car(car);
	forkk(car, arena);
}
