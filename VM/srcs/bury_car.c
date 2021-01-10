/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bury_car.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:38:09 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/10 20:56:20 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	bury_car(t_vm *vm, t_car **head_car)
{
	t_car *cur;
	t_car *del;
	
	del = NULL;
	cur = (*head_car);
	while (cur)
	{
		if ((vm->cycles_to_die <= 0)
		|| (vm->cycles - cur->last_live) >= vm->cycles_to_die)
		{
			vm->car_count--;
			del = cur;
			cur = cur->next;
			ft_memdel((void*)del);
		}
		cur = cur->next;
	}
}
