/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:27:10 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/22 18:42:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

void        arena_initialize(t_vm *vm)
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
}
