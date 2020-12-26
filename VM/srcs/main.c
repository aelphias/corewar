/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/23 22:53:42 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_flg *flg;
	
	argc == 1 ? print_error(ERR_USE) : 0;
	if (!(flg = (void*)ft_memalloc(sizeof(t_flg))))
		print_error(ERR_MALLOC);
	ft_parse(argc - 1, argv, flg);
	//test(flg, plr);
	return (0);
}
