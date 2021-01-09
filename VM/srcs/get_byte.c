/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_byte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:31:49 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/09 21:31:52 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t	get_byte(uint8_t *arena, unsigned int position)
{
	if (position >= MEM_SIZE)
		position = position % MEM_SIZE;
	ft_printf("{inside get_byte = %x}\n", arena[position]);
	return (arena[position]);  // May be position - 1? 
}
