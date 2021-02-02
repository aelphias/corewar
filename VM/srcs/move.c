/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:35:08 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 19:09:06 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		move(t_car *car)
{
	int	i;
	int	move;

	i = -1;
	move = 0;
	while (++i < 3)
	{
		if (car->arg_type[i] != 0)
		{
			if (car->arg_type[i] == T_REG)
				move += 1;
			else if (car->arg_type[i] == T_DIR)
			{
				if (car->dir_size_status == 4)
					move += 4;
				else
					move += 2;
			}
			else if (car->arg_type[i] == T_IND)
				move += 2;
		}
		else
			move += 0;
	}
	return (move);
}
