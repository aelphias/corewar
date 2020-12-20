/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:35:34 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/19 21:36:14 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_error(int num_error)
{
	if (num_error == 1)
	{
		ft_putstr_fd("Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor]\n", 2);
	}
	else if (num_error == 2)
	{
		ft_putstr_fd("Too many players, %d is max ", 2);
		ft_putnbr_fd(MAX_PLAYERS, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (num_error == 3)
		ft_putstr_fd("Could not allocate memory\n", 2);
	exit(-1);
}