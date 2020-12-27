/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:13:14 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/27 15:56:10 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	test(t_flg *flg, t_plr *plr)
{
	ft_printf("****Testing!****\n");
	ft_printf("dump=%d\n", flg->dump);
	ft_printf("n=%d\n", flg->n);
	printf("plr->name=%s\n", plr->name);
	ft_printf("****Testing!****\n");
}
