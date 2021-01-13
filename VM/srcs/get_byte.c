/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_byte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:31:49 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/13 22:39:05 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t	get_byte(uint8_t *arena, unsigned int pos, t_car *car)
{
	if ((pos + car->step) >= MEM_SIZE)
		pos = (pos + car->step) % MEM_SIZE;
	return (arena[pos]); 
}
