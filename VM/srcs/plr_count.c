/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plr_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:57:45 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/27 16:33:17 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	plr_count(t_plr *head)
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
