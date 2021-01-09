/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:43:04 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/09 18:00:14 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	update_pos(unsigned int pos)
{
	if (pos >= MEM_SIZE)
		pos = pos % MEM_SIZE;
	return (pos); // было так
}
