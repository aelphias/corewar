/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:35:08 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/24 15:51:44 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		move(t_car *car)
{
	int i;
	int	move;

	i = 0;
	move = 0;
	while (i < 3)
	{
		if (car->arg_type[i] != 0)
		{
			if (car->arg_type[i] == REG_CODE)
				move += 1;
			else if (car->arg_type[i] == DIR_CODE)
			{
				if (car->dir_size_status == 4) //dir_size_status true if T_DIR == 4, els T_DIR = 2
					move += 4;
				else
					move += 2;
			}
			else if (car->arg_type[i] == IND_CODE)
				move += 2;
		}
		else
			move += 0;
		i++;
	}
	return (move);
}
