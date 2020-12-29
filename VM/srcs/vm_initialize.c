/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:36:54 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/27 15:56:13 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

t_vm    *vm_initialize(void)
{
    t_vm *vm;
    
    if (!(vm = (void*)ft_memalloc(sizeof(t_vm))))
        print_error();
}
