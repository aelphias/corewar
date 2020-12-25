/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:27:10 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/25 19:18:44 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

/*void        arena_initialize(t_vm *vm)
{
	int     id_pl;
	int     p;

	id_pl = 1;
	p = 0;
	while (id_pl <= vm->arena[p])
	{
		p += MEM_SIZE / vm->nop;
		id_pl++;
	}
}*/

void		init_arena(t_vm *vm)
{
	int			id;
	unsigned	plays_on_mem;

	id = 1;
	plays_on_mem = 0;
	while (id <= vm->num_of_plrs)
	{
		ft_memcpy(&(vm->arena[plays_on_mem]),
			vm->players[INDEX(id)]->code,
			(size_t)(vm->players[INDEX(id)]->code_size));
		plays_on_mem += MEM_SIZE / vm->num_of_plrs;
		id++;
	}
}

