/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:40:21 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/27 15:56:07 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

t_plr       plr_init(int id_pl)
{
    t_plr *plr;

	if (!(plr = (t_plr *)ft_memalloc(sizeof(t_plr))))
		call_error();
	plr->id = id_pl;
	plr->name = NULL;
	plr->cmnt = NULL;
	plr->code = NULL;
	plr->next = NULL;
}
