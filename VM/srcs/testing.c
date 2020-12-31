/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:13:14 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/28 22:14:45 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_list_car(t_car *car)
{
	int i;

	i = 1;
	ft_printf("<<<< t_car *car >>>>\n", i);
	while (car) 
	{	ft_printf("<<<<%d>>>>\n", i);
		printf("car->id= %d\n", car->id);
		printf("position= %d\n", car->position);
		printf("code= %d\n", car->code);
		car = car->next;
		i++;
	}
}

void	test(t_vm *vm, t_plr *plr)
{
	ft_printf("****Testing!****\n");
	ft_printf("dump=%d\n", vm->dump);
	ft_printf("n=%d\n", vm->n);
	printf("plr->name=%s\n", plr->name);
	ft_printf("****Testing!****\n");
}
