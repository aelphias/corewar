/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:25:16 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 20:54:20 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		check_carry_status(int val, t_car *car)
{
	if (val == 0)
		car->carry = 1;
	else
		car->carry = 0;
}

void		ft_free_plr(t_plr *plr)
{
	t_plr	*tmp;

	while (plr != NULL)
	{
		tmp = plr;
		plr = plr->next;
		ft_memdel((void**)&tmp->cmnt);
		ft_memdel((void**)&tmp->code);
		ft_memdel((void**)&tmp->name);
		ft_memdel((void**)&tmp);
	}
}

void		del_car(t_car *head_car)
{
	t_car	*tmp;

	while (head_car)
	{
		tmp = head_car;
		head_car = head_car->next;
		ft_memdel((void**)&tmp->arg);
		ft_memdel((void**)&tmp->arg_type);
		ft_memdel((void**)&tmp);
		ft_memdel((void**)&head_car);
	}
}

void		free_all(t_plr *plr, t_vm *vm, t_car *head_car)
{
	head_car ? del_car(head_car) : 0;
	plr ? ft_free_plr(plr) : 0;
	vm ? ft_memdel((void**)&vm) : 0;
	exit(0);
}
