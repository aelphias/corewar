/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/20 20:07:06 by aelphias         ###   ########.fr       */
=======
/*   Updated: 2020/12/19 21:10:20 by aelphias         ###   ########.fr       */
>>>>>>> 9c1ee0882eb7d560c543d5fda39774a9f00546f0
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** strerror
** perror
*/
void init(t_flg *flg, t_plr *plr)
{
	
	ft_bzero(flg, sizeof(t_flg));
	ft_bzero(plr, sizeof(t_plr));
}


int	main(int argc, char **argv)
{
<<<<<<< HEAD
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
=======
	t_flg *flag;

	if (!(flag = (void*)malloc(sizeof(t_flg))))
		print_error(ERR_MALLOC);
		argc == 1 ? print_error(ERR_USE) : 0;
	ft_parse(argc - 1, argv, flag);
>>>>>>> 9c1ee0882eb7d560c543d5fda39774a9f00546f0
	return (0);
}
