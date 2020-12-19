/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:10 by aelphias          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/19 15:11:55 by gjigglyp         ###   ########.fr       */
=======
/*   Updated: 2020/12/19 15:12:37 by aelphias         ###   ########.fr       */
>>>>>>> b833810c6eb9cec44ced071bd7d19a6fb9ba32cc
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"



void	ft_parse(int argc, char **argv, t_flg *flag)
{
	check_flags(argc, argv, flag);
	//check_filename(argc, argv);
	/*
	*checking filename and magic header
	*/
	MAX_PLAYERS < argc ? print_error(ERR_M_PLRS) : 0; //check .cor implicitely 
}