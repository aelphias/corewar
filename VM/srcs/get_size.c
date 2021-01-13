/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:44:48 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/13 18:11:14 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int         get_size(unsigned char *map, int cmd, int size)
{
    int     temp;
    int     result;
    
    result = 0;
    if ((g_op[cmd]).code > 0)
    {
        temp = get_map(map, size + 1);
        result *= weight(bitmask_corr(1, temp), cmd);
        if (cmd != 16)
            result += weight(bit_mask(2, temp), cmd);
		if (cmd != 3 && cmd != 2 && cmd != 13 && cmd != 16)
			result += weight(bit_mask(3, temp), cmd);
		return (result + 2);
	}
	return (g_op[cmd].dir_size_status + 1);
}

int			weight(int a, int c)
{
    if (a == 3)
        return (g_op[c].dir_size_status);
    else if (a == 2)
        return (2);
    else if (a == 1)
        return (1);
    return (0);
}