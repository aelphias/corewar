/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/23 20:44:45 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** strerror
** perror
*/
void init(t_flg *flg, t_plr *plr)
{
	flg->dump = 0;
	flg->n = 0;
	plr->name = NULL;
	plr->plr_count = 0;
}


int	main(int argc, char **argv)
{
	t_flg *flg;
	t_plr *plr;
	
	argc == 1 ? print_error(ERR_USE) : 0;
	if (!(flg = (void*)malloc(sizeof(t_flg))))
		print_error(ERR_MALLOC);
	if (!(plr = (void*)malloc(sizeof(t_plr))))
		print_error(ERR_MALLOC);
	init(flg, plr);
	ft_parse(argc - 1, argv, flg, plr);
	test(flg, plr);
	return (0);
}
