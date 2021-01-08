/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:01:29 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/07 22:20:03 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t	get_op_code(uint8_t *arena, uint32_t position)
{
	ft_printf("{inside get_op_code = %d}", position);
	if (position >= MEM_SIZE)
	position = position % MEM_SIZE;
	return (arena[position]);  // May be position - 1? 
}
