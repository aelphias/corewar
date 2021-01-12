/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_mask_oper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:40:38 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/11 21:43:55 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int     bitmask_corr(int a, int size)
{
    int bm;

    if (a == 1)
        bm = 192;
    else
    {
        if (a == 2)
            bm = 48;
        else
            bm = 12;    
    }
    if ((size & bm) == (bm * 2 / 3))
        return (3);
    if ((size & bm) == bm)
        return (2);
    if ((size & bm) == (bm / 3))
        return (1);
    return (0);
}

