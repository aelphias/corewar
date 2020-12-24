/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:10 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/23 17:58:57 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

// viod read_nameint(argc, char **argv, t_plr *plr)
// {
// 	int i;

// 	i = 0;
// 	while (i < argc)
// 	{
		
// 	}
// }

void	ft_parse(int argc, char **argv, t_flg *flg, t_plr *plr)
{
	//read_name(argc, argv, plr)
	check_flags(argc, argv, flg, plr);
	
	//check_filename(argc, argv);
	/*
	*checking filename and magic header
	*/
	//MAX_PLAYERS < argc ? print_error(ERR_M_PLRS) : 0; //check .cor implicitely 
}