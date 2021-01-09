/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:01:29 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/09 17:51:36 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t	get_op_code(uint8_t *arena, unsigned int position)
{
	if (position >= MEM_SIZE)
		position = position % MEM_SIZE;
	ft_printf("{inside get_op_code = %x}\n", arena[position]);
	return (arena[position]);  // May be position - 1? 
}
