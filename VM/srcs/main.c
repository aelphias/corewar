/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/25 18:18:39 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_flg *flg;
	t_plr *plr; //  will void *p; work the same way?
	
	( argc == 1 || argc > 5 ) ? print_error(ERR_USE) : 0;
	if (!(flg = (t_flg *)ft_memalloc(sizeof(t_flg))))
		print_error(ERR_MALLOC);
	/* if (!(plr = (void*)ft_memalloc(sizeof(t_plr))))
		print_error(ERR_MALLOC); */
	ft_parse(argc - 1, argv, flg, &plr);
	//test(flg, &plr);
	return (0);
}
