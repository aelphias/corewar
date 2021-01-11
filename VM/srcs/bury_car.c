/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bury_car.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:38:09 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/11 12:30:52 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	bury_car(t_vm *vm, t_car **head_car)
{
	t_car *current;
	t_car *del;
	
	del = NULL;
	current = (*head_car);
	while (current)
	{
		if ((vm->cycles_to_die <= 0)
		|| (vm->cycles - current->last_live) >= vm->cycles_to_die)
		{
			vm->car_count--;
			del = current;
			if (current == (*head_car)) // deleting from head
			{
				current = current->next;
				free(del);
			}
		}
	}
}
