/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 13:30:59 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/25 14:59:56 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	is_num(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	printf("{is_num OK}\n");
	return (1);
}

void create_list_plr(t_plr *head, int val)
{
    t_plr * current = head;

    while (current->next != NULL) 
        current = current->next;
	if (!(current->next = (void*)ft_memalloc(sizeof(t_plr))))
 		print_error(ERR_MALLOC);
    current->next->id = val;
    current->next->next = NULL;
}

void print_list(t_plr *plr) 
{
    t_plr *current = plr;
    while (current != NULL) 
	{
        printf("%d\n", current->id);
    	current = current->next;
	}
}
