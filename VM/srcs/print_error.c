/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:35:34 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/18 18:52:44 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_error(int num_error)
{
	if (num_error == 1)
	{
		ft_printf("Usage: ./corewar...\n");
	}
	else if (num_error == 2)
		ft_printf("Too many players, %d is max\n", MAX_PLAYERS);
	
	exit(-1);
}