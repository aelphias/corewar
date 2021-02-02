/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:39:28 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/27 12:02:47 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_copy_code(uint8_t *dst, uint8_t *src, int codesize)
{
	int i;

	i = 0;
	while (i < codesize)
	{
		dst[i] = src[i];
		i++;
	}
}

void	fill_arena(t_plr *plr, uint8_t *arena)
{
	int i;

	i = 0;
	while (plr)
	{
		ft_copy_code(&(arena[plr->pos]), plr->code, plr->codesize);
		plr = plr->next;
	}
}
