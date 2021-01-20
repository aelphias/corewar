/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:43:04 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/20 19:23:25 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	update_pos(unsigned int pos)
{
	pos = pos % (MEM_SIZE - 1); //should we use - 1?
	return (pos);
}
