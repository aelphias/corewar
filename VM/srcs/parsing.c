/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:10 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/23 17:58:57 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

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

// void print_list(t_plr *plr) 
// {
//     t_plr *current = plr;
//     while (current != NULL) 
// 	{
//         printf("%d\n", current->id);
//     	current = current->next;
// 	}
// }

void	ft_parse(int argc, char **argv, t_flg *flg, t_plr *plr)
{
	int i = 1;
	while (i < 4)
		create_list_plr(plr, i++);
	print_list(plr);
	//check_flags(argc, argv, flg, plr);
	
	//check_filename(argc, argv);
	/*
	*checking filename and magic header
	*/
	//MAX_PLAYERS < argc ? print_error(ERR_M_PLRS) : 0; //check .cor implicitely 
}