/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:57:45 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/11 20:23:12 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int				plr_count(t_plr *head)
{
	int count;

	count = 0;
	if (head == NULL)
		return (0);
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}
