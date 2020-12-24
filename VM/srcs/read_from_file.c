/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:45:52 by kcharlet          #+#    #+#             */
/*   Updated: 2020/12/24 19:37:42 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		read_from_file(t_plr *player, char *str, int nbr)
{
	t_plr	*chemp;
	t_plr	*test;

	chemp = NULL;
	test = player;
	if (!(chemp = read_p_from_f(str, nbr)))
		return (1);
	else
	{
		if (player == NULL)
			player = chemp;
		else
		{
			while (test->next != NULL)
				test = test->next;
			test->next = chemp;
		}
	}
	return (0);
}