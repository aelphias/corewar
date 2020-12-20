/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:10 by aelphias          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/20 19:55:06 by aelphias         ###   ########.fr       */
=======
/*   Updated: 2020/12/19 20:56:06 by aelphias         ###   ########.fr       */
/*   Updated: 2020/12/19 19:20:27 by gjigglyp         ###   ########.fr       */
>>>>>>> 9c1ee0882eb7d560c543d5fda39774a9f00546f0
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"



void	ft_parse(int argc, char **argv, t_flg *flg, t_plr *plr)
{
	check_flags(argc, argv, flg, plr);
	//check_filename(argc, argv);
	/*
	*checking filename and magic header
	*/
	//MAX_PLAYERS < argc ? print_error(ERR_M_PLRS) : 0; //check .cor implicitely 
}