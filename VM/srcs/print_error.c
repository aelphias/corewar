/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:35:34 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/11 17:00:30 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_error(int num_error)
{
	if (num_error == 1)
		ft_putstr_fd("Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor]\n", 2);
	else if (num_error == 2)
	{
		ft_putstr_fd("Too many players, %d is max ", 2);
		ft_putnbr_fd(MAX_PLAYERS, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (num_error == 3)
		ft_putstr_fd("Could not allocate memory\n", 2);
	else if (num_error == 4)
		ft_putstr_fd("Could not parse\n", 2);
	else if (num_error == 5)
		ft_putstr_fd("Could create carriage\n", 2);
	// free structs before exit()
	exit(1);
}

void	error_one_dump()
{
	//free
	write(2, "USE ONE VALUE FOR DUMP\n", 23);
	exit(1);
}

void	error_pos_number()
{
	//free
	write(2, "USE POSITIVE NUMBER FOR DUMP\n", 29);
	exit(1);
}
