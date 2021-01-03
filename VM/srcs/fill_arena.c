/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:39:28 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/03 19:56:06 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_copy_code(unsigned char *dst, unsigned int *src, int codesize)
{
	size_t i;

	i = 0;
	while (i < codesize) // почему 48? обрааааати на это вниманеи возможно изза длины кода леъхи
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
		ft_copy_code(&(arena[plr->position]), plr->code, plr->codesize);
		plr = plr->next;
	}
	if (vm->dump)
	{
		dump(arena);
		ft_printf("dump=%d\n ",vm->dump);
	}
	}
		
