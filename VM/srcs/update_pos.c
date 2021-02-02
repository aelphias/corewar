/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:43:04 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/31 18:07:29 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		update_pos(int pos)
{
	pos = pos % MEM_SIZE;
	if (pos < 0)
		pos = MEM_SIZE + pos;
	return (pos % MEM_SIZE);
}

void	walk(t_car *car, int steps)
{
	car->pos = update_pos(car->pos + steps);
}

uint8_t	get_byte(uint8_t *arena, t_car *car)
{
	return (arena[update_pos(car->pos)]);
}
