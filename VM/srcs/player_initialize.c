/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:40:21 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/22 18:41:32 by gjigglyp         ###   ########.fr       */
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
	plr->soc = 0;
	plr->code = NULL;
	plr->ll = 0;
	plr->cur_ln = 0;
	plr->prev_ln = 0;
	plr->next = NULL;
}