/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_byte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:31:49 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/18 17:33:32 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t	get_byte(uint8_t *arena, t_car *car)
{
	if ((car->pos) >= MEM_SIZE)
		car->pos = car->pos % MEM_SIZE;
	return (arena[car->pos]); 
}
