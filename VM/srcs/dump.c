/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:46:26 by kcharlet          #+#    #+#             */
/*   Updated: 2021/02/02 20:01:45 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	dump(uint8_t *arena)
{
	int			j;
	int			i;

	j = 0;
	i = 0;
	ft_printf("0x0000 : ");
	while (++i <= MEM_SIZE)
	{
		ft_printf("%02x ", arena[i - 1]);
		if (i % 32 == 0 && i != 0)
		{
			ft_printf("\n");
			(i < MEM_SIZE) ? ft_printf("0x%04x : ", i) : 0;
		}
	}
}
