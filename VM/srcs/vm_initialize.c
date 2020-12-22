/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:36:54 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/22 15:39:59 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

t_vm    *vm_initialize(void)
{
    t_vm vm;
    
    if (!(vm = (t_vm*)ft_memalloc(sizeof(t_vm))))
        call_error();
    vm->nop = 0;
    vm->cycles = 0;
    vm->c2d = 0;
    vm->cac = 0;
    vm->print_mode = 0;
}