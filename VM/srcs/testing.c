/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:13:14 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/24 19:42:10 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_list_car(t_car *car)
{
	ft_printf("<<<< КАРЕТКИ ПОШЛИ >>>>\n");
	
	while (car) 
	{	
		printf("car->id= %d\n", car->id);
		printf("pos= %d\n", car->pos);
		printf("\n");
		car = car->next;
	}
}

void print_list(t_plr *plr) 
{
	int i;

	i = 0;
	ft_printf("<<<< ИГРОКИ ПОШЛИ >>>>\n");
	while (plr) 
	{
		printf("plr->id %d\n", plr->id);
		printf("plr->name %s\n", plr->name);
		ft_printf("plr->cmnt %s\n", plr->cmnt);
		ft_printf("code \n");
		while (i < 50)
			ft_printf("%x ", plr->code[i++]);
		ft_printf("\n");
		ft_printf("codesize=%d\n", plr->codesize);
		plr = plr->next;
		i = 0;
	}
}

void	test(t_vm *vm, t_plr *plr)
{
	ft_printf("****Testing!****\n");
	ft_printf("dump=%d\n", vm->dump);
	ft_printf("n=%d\n", vm->n);
	printf("plr->name=%s\n", plr->name);
	ft_printf("****Testing!****\n");
}


/* 
from reading args
printf("READING FROM ARENA%\n");
		printf("[%d] ", arg_type);

		printf("[i]", car->arg_type[i]);

		int i = 0;
	while (i < 3)
	{
		printf("[i]", car->arg_type[i]);
		i++;
	}
		printf("<-->\n");
 */

/*  WARNING!
** TESTING! REMOVE OR COMMENT AFTER USE! --------->
**use with following code in .s file:
**ld 5, r16
**
**arena[8] = 4;
**printf("for test we added arena[8] = 4\n");
**dump(arena);
** <------------------
**	WARNING!
**TESTING! REMOVE OR COMMENT AFTER USE!
*/
