/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n_flag_cont.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:13:41 by marvin            #+#    #+#             */
/*   Updated: 2021/01/11 20:14:56 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		chek_num(int *num, int minnum, int plrs)
{
	int	i;

	i = 0;
	while (i < plrs)
	{
		if (num[i] == minnum)
			return (0);
		i++;
	}
	return (1);
}

int		right_n_flag(int argc, char **argv)
{
	int	i;
	int	nflag;

	i = 0;
	nflag = 0;
	while (i < argc)
	{
		if ((ft_strcmp(argv[i], "-n")) == 0)
		{
			nflag = 1;
			break ;
		}
		i++;
	}
	return (nflag);
}

int		number_after_n(int i, char **argv)
{
	int	number;

	number = 0;
	number = ft_atoi(argv[i - 1]);
	if (number == 0)
		print_error(ERR_USE);
	return (number);
}

void	put_number_in_arr(int *num, t_plr *plr, int plrs)
{
	int i;
	int nextnum;
	int j;

	nextnum = 0;
	i = 0;
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
}
