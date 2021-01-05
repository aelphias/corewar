/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:39:28 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/05 21:11:41 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_copy_code(uint8_t *dst, uint8_t *src, int codesize)
{
	int i;

	i = 0;
	while (i < codesize) // почему 48? обрааааати на это вниманеи возможно изза длины кода леъхи
	{
		dst[i] = src[i];
		i++;
	}
}


void	fill_arena(t_plr *plr, t_vm *vm, uint8_t *arena)
{
	int i;
	
	i = 0;
	while (plr)
	{
		ft_copy_code(&(arena[plr->position]), plr->code, plr->codesize);
		plr = plr->next;
	}
	if ((vm->dump) != -1)
	{
		dump(arena);
		ft_printf("dump=%d\n ",vm->dump);
	}
	}
		
