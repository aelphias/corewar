/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:10 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/25 14:59:46 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

void	ft_parse(int argc, char **argv, t_flg *flg, t_plr **plr)
{
	/* int i = 1;
	while (i < 10)
		create_list_plr(plr, i++);
	print_list(plr); */
	check_flags(argc, argv, flg, plr);
	
	//check_filename(argc, argv);
	/*
	*checking filename and magic header
	*/
	//MAX_PLAYERS < argc ? print_error(ERR_M_PLRS) : 0; //check .cor implicitely 
}