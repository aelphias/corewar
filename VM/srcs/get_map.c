/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:01:29 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/06 15:48:54 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_map(uint8_t *arena, int coord)
{
	if (coord < 0)
	coord = coord + MEM_SIZE;

	if (coord >= MEM_SIZE)
	coord = coord - MEM_SIZE;
	return (arena[coord]);
}
