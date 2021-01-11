/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bury_car.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:38:09 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/11 16:08:48 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_car	*item_deletion(t_car *current)
{
	t_car *next;
	
    if (current->demolish) { // Found one to delete
        next = current->next;
        free(current);
        return (next);
    } else { // Just keep going
        current->next = item_deletion(current->next);
        return (current);
    }
}

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
			item_deletion(current);
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