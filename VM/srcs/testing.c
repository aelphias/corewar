/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:13:14 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/28 18:03:12 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	test(t_vm *vm, t_plr *plr)
{
	ft_printf("****Testing!****\n");
	ft_printf("dump=%d\n", vm->dump);
	ft_printf("n=%d\n", vm->n);
	printf("plr->name=%s\n", plr->name);
	ft_printf("****Testing!****\n");
}
