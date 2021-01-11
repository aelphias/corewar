/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bury_car.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:38:09 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/11 15:32:58 by aelphias         ###   ########.fr       */
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
			else if (!(current->next))
			{
				free(del);
				break;
			}
			else
			{
				current = current->next->next;
				free(del);
			}
			current = current->next;
		}
		else
			current = current->next;
	}
}


/* void	bury_car(t_vm *vm, t_car **head_car)
{
	t_car *current;
	t_car *del;
	
	del = NULL;
	current = (*head_car);
	while (current && current->next)
	{
		if ((vm->cycles_to_die <= 0)
		|| (vm->cycles - current->last_live) >= vm->cycles_to_die)
		{
			vm->car_count--;
			del = current->next;
			current->next = current->next->next;
			free(del);
		}
		current = (*head_car);
		if (current)
		{
			*head_car = current->next;
			free(current);
		}
	}
} */


/* void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*remove;
	t_list	*current;

	current = *begin_list;
	while (current && current->next)
	{
		if ((*cmp)(current->next->data, data_ref) == 0)
		{
			remove = current->next;
			current->next = current->next->next;
			free(remove);
		}
		current = current->next;
	}
	current = *begin_list;
	if (current && (*cmp)(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
	}
} */