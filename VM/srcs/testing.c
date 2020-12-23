/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:13:14 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/20 20:20:19 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	test(t_flg *flg, t_plr *plr)
{
	ft_printf("dump=%d\n", flg->dump);
	ft_printf("n=%d\n", flg->n);
	ft_printf("plr->name=%d\n", plr->name);
}