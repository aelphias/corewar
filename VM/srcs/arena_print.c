/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:46:58 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/22 18:07:39 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

void        last_alived_print(t_vm *vm)
{
    //ft_printf("Contestant %d, %s HAS WON!\n");
}

void        arena_print(int pm, int *arena)
{
    int p;
    int q;
    
    p = 0;
    while (p < MEM_SIZE)
    {
        ft_printf("%.4p : ", p);
        q = 0;
        while (q < pm)
        {
            ft_printf("%.2x", arena[p + q]);
            q++;
        }
        write(1, "\n", 1);
        p += pm;
    }
}
