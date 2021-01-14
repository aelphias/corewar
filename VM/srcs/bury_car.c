/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bury_car.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:38:09 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/14 22:28:33 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	bury_car(t_vm *vm, t_car **head_car)
{
	t_car *current;
	t_car *prev;
	t_car *del;
	
	prev = NULL;
	current = *head_car;
	while (current)
	{
		if ((vm->cycles_to_die <= 0)
		|| (vm->cycles - current->last_live_cycle) >= vm->cycles_to_die)
		{	
			vm->car_count--;
			del = current;
			current = current->next;
			if ((*head_car) == del)
				(*head_car) = current;
			if (prev)
				prev->next = current;
			ft_memdel((void**)&del);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
