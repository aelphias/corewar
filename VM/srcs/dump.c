/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:46:26 by kcharlet          #+#    #+#             */
/*   Updated: 2020/12/31 14:04:47 by aelphias         ###   ########.fr       */
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
		if (i % 32 == 0 && i != 0)   // здесь можно изменить ширину вывода
			ft_printf("\n");
	// добавить зависимость от цикла
	}
}
