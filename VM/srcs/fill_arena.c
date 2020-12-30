/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:39:28 by kcharlet          #+#    #+#             */
/*   Updated: 2020/12/30 14:40:54 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_copy_code(unsigned char *dst, unsigned int *src)
{
	size_t i;

	i = 0;
	while (i < 48) // почему 48?
	{
		dst[i] = src[i];
		i++;
	}
}


void	fill_arena(t_plr *plr, t_vm *vm, unsigned char *arena)
{
	int i;
	
	i = 0;
	while (plr)
	{
		ft_copy_code(&(arena[plr->position]), plr->code);
		plr = plr->next;
	}
	dump(arena);
}
