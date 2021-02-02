/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce_plrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:09:50 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/17 20:49:56 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	introduce_plrs(t_plr *plr)
{
	uint8_t i;

	i = 1;
	ft_printf("Introducing contestants...\n");
	while (plr)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", \
			i++, plr->codesize, plr->name, plr->cmnt);
		plr = plr->next;
	}
}
