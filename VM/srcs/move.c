/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:35:08 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/14 16:36:32 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int move(t_car *car)
{
    int i;
    
    i = 0;
	while (i < 3)
	{
		if (car->arg_type[i] != 0)
		{
			if (car->arg_type[i] == T_REG)
				car->move += 1;
			else if (car->arg_type[i] == T_DIR)
			{
				if (car->dir_size_status == 4) //dir_size_status true if T_DIR == 4, els T_DIR = 2
					car->move += 4;
				else
					car->move += 2;
			}
			else if (car->arg_type[i] == T_IND)
				car->move += 2;
		}
		else
			car->move += 0;
		i++;
	}
    return (car->move);
}
