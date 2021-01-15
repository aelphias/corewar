/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numb_in_arena.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:47:44 by sdarron           #+#    #+#             */
/*   Updated: 2021/01/15 19:18:07 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		put_numb_in_arena(uint8_t *arena, int new_adr, int val_in_reg1, int size)
{
	int8_t	i;

	i = 0;
	while (size)
	{
		arena[update_pos(new_adr + size - 1)] = (uint8_t)((val_in_reg1 >> i) & 255);
		i += 8;
		size--;
	}
}
