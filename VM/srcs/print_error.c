/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:35:34 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/28 19:15:53 by kcharlet         ###   ########.fr       */
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
