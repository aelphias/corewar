/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_byte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:31:49 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/13 12:42:50 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t	get_byte(uint8_t *arena, unsigned int pos)
{
	if (pos >= MEM_SIZE)
		pos = pos % MEM_SIZE;
	return (arena[pos]);  // May be pos - 1? 
}
