/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_value_in_arena.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:47:44 by sdarron           #+#    #+#             */
/*   Updated: 2021/01/30 13:56:10 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		put_value_in_arena(uint8_t *aren, int new_ad, int val_rg1, int sz)
{
	int8_t	i;

	i = 0;
	while (sz)
	{
		aren[update_pos(new_ad + sz - 1)] =
		(uint8_t)((val_rg1 >> i) & 255);
		i += 8;
		sz--;
	}
}
