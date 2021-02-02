/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:07:54 by marvin            #+#    #+#             */
/*   Updated: 2021/01/11 20:22:14 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		copy_num_in_plrslist(int *num, t_plr *plr, int plrs)
{
	int		i;

	i = 0;
	while (plr && i < plrs)
	{
		plr->n_id = num[i];
		plr = plr->next;
		i++;
	}
}

int			comparison_of_two_numbers(int a, int b)
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

void		check_same_numb(int *num, t_plr *plr, int plrs)
{
	int		i;
	int		j;

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
	put_number_in_arr(num, plr, plrs);
}

void		checkdotcor_and_chech_n(int ac, char **av, int *n, t_plr *pr)
{
	int		i;
	int		j;
	int		prs;

	prs = plr_count(pr);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (checkdotcor(av[i]))
		{
			if (i > 2 && (ft_strcmp(av[i - 2], "-n")) == 0)
				n[j] = number_after_n(i, av);
			else
				n[j] = 0;
			if (j > prs)
				print_error(ERR_USE);
			if (n[j] > prs)
				print_error(ERR_USE);
			j++;
		}
		i++;
	}
	check_same_numb(n, pr, prs);
}
