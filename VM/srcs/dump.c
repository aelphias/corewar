/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:46:26 by kcharlet          #+#    #+#             */
/*   Updated: 2020/12/30 16:50:55 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump(unsigned char *arena)
{
	int i;

	i = 0;
	while (++i <= MEM_SIZE) 
	{
		ft_printf("%02x ", arena[i - 1]);
		if (i % 64 == 0 && i != 0)
			ft_printf("\n");
	// добавить зависимость от цикла
	}
}
