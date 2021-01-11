/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:51:41 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/11 14:53:49 by aelphias         ###   ########.fr       */
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
	return (1);
}

void check_flags(int argc, char **argv, t_vm *vm)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (i <= argc)
	{
		if ((ft_strcmp(argv[i], "-dump")) == 0)
		{	
			if (argc <= 2)
				print_error(ERR_USE);
			if (argc == i)
				print_error(ERR_USE);
			if (flag == 1)
				error_one_dump();
			if (!(is_num(argv[i + 1])))
				print_error(ERR_USE);
			vm->dump = ft_atoi(argv[i + 1]);
			flag = 1;
			if (vm->dump < 0)
				error_pos_dump();
		}
		i++;
	}
}

int chek_num(int *num, int minnum, int plrs)
{
	int i;

	i = 0;
	while (i < plrs)
	{
		if (num[i] == minnum)
			return (0);
		i++;
	}
	return (1);
}

void copy_num_in_plrslist(int *num, t_plr *plr, int plrs)
{
	int i;

	i = 0;
	while (plr && i < plrs)
	{
		plr->n_id = num[i];
		plr = plr->next;
		i++;
	}
}

int comparison_of_two_numbers(int a, int b)
{
	return (a <= b);
}

t_plr		*sort_list_plr(t_plr *plr)
{
	int		overflow;
	t_plr	*tmp;

	tmp = plr;
	while (plr->next != NULL)
	{
		if ((comparison_of_two_numbers(plr->n_id, plr->next->n_id)) == 0)
		{
			overflow = plr->n_id;
			plr->n_id = plr->next->n_id;
			plr->next->n_id = overflow;
			plr = tmp;
		}
		else
			plr = plr->next;
	}
	plr = tmp;
	return (plr);
}

void check_n_flags(int argc, char **argv, t_plr *plr)
{
	int i;
	int j;
	int num[4];
	int number;
	int plrs;
	int nflag;
	
	plrs = plr_count(plr);
	nflag = 0;
	i = 0;
	j = 0;
	ft_bzero(num, 0);
	while (i < argc)
	{
		if ((ft_strcmp(argv[i], "-n")) == 0)
		{
			nflag = 1;
			break ;
		}
		i++;
	}
	i = 1;
	if (nflag)
	{
		while (i < argc)
		{
			if (checkdotcor(argv[i]))
			{
				if (i > 2 && (ft_strcmp(argv[i - 2], "-n")) == 0)
				{
					number = ft_atoi(argv[i - 1]);
					if (number == 0)
						print_error(ERR_USE);
					num[j] = number;
				}
				else
					num[j] = 0;
				if (j > plrs)
					print_error(ERR_USE);
				if (num[j] > plrs )
					print_error(ERR_USE);
				j++;
			}
			i++;
		}
		i = 0;
		j = 1;
		while (i <= plrs)
		{
			while (j < plrs)
			{
				if (num[i] != 0)
					if (num[i] == num[j])
						print_error(ERR_USE);
				j++;
			}
			i++;
			j = i + 1;
		}
	
		i = 0;
		int nextnum;
		nextnum = 0;
		while (i <= plrs)
		{
			if (chek_num(num, i, plrs))
			{
				nextnum = i;
				j = 0;
				while (j < plrs)
				{
					if (num[j] == 0)
					{
						num[j] = nextnum;
						break ;
					}
					j++;
				}
			}
			i++;
		}

		copy_num_in_plrslist(num, plr, plrs);
		plr = sort_list_plr(plr);
			
		// i = 0;
		// while (i < plrs)
		// {
		// 	ft_printf(" %d ", num[i]);
		// 	i++;
		// }
		// ft_printf("\n");
		// while (plr)
		// {
		// 	printf(" list %d ", plr->n_id);
		// 	plr = plr->next;
		// }
		// ft_printf("\n");
	}
}

