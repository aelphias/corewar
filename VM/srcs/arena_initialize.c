/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:27:10 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/28 16:52:33 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

void		arena_initialize(t_vm *vm)
{
	int		id_pl;
	int		p;

	id_pl = 1;
	p = 0;
	while (id_pl <= vm->arena[p])
	{
		p += MEM_SIZE / vm->nop;
		id_pl++;
	}
}
