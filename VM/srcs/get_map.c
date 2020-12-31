/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:01:29 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/31 16:06:20 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_map(unsigned char *arena, int coord)
{
	if (coord < 0)
	coord = coord + MEM_SIZE;

	if (coord >= MEM_SIZE)
	coord = coord - MEM_SIZE;
	
	return (arena[coord]);
}
