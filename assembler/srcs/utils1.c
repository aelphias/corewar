/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:44:06 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/29 18:44:03 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_strjoin_for_asm(char *l1, char *l2, int flag)
{
	char	*l3;
	char	*l4;

	if (!l1 || !l2)
		return (0);
	l3 = ft_strdup(l1);
	l4 = ft_strdup(l2);
	free(l1);
	l1 = ft_strjoin(l3, l4);
	if (flag == 1)
		free(l2);
	free(l3);
	l3 = ft_strdup(l1);
	free(l1);
	l1 = ft_strjoin(l3, "\n");
	free(l3);
	free(l4);
	return (l1);
}

void		count_lbl(t_lbl *label, t_cmnd *cmnd)
{
	if (cmnd->arg_is_lbl[0] != 0)
	{
		while (--cmnd->arg_is_lbl[0] > 0)
			label = label->next;
		cmnd->argument[0] = label->pos - cmnd->pos;
	}
	else if (cmnd->arg_is_lbl[1] != 0)
	{
		while (--cmnd->arg_is_lbl[1] > 0)
			label = label->next;
		cmnd->argument[1] = label->pos - cmnd->pos;
	}
	else if (cmnd->arg_is_lbl[2] != 0)
	{
		while (--cmnd->arg_is_lbl[2] > 0)
			label = label->next;
		cmnd->argument[2] = label->pos - cmnd->pos;
	}
}

/*
** c[0] = code, c[1] = count, c[2] = i
*/

int			sc(t_cmnd *cmnd)
{
	int		c[3];

	c[1] = 3;
	c[2] = 0;
	c[0] = 0;
	while (c[1]--)
	{
		while (c[2] <= 2)
		{
			c[0] += (cmnd->argtype[c[2]]);
			c[0] <<= 2;
			c[2]++;
		}
	}
	return (c[0]);
}

void		free_str_arr(char **str, char ***arr, int flag)
{
	int		i;

	if ((flag == 1 || flag == 2) && *str != 0)
	{
		free(*str);
		*str = 0;
	}
	if ((flag == 0 || flag == 2) && arr != 0 && *arr != 0)
	{
		i = 0;
		while (arr[0][i])
		{
			free(arr[0][i]);
			arr[0][i] = 0;
			i++;
		}
		free(*arr);
		*arr = 0;
	}
}

void		checkfs(t_crw *crw)
{
	while (crw->af[crw->arp] != '\n' && crw->af[crw->arp] != COMMENT_CHAR && \
			crw->af[crw->arp] != ALT_COMMENT)
	{
		if (if_is_space(crw->af[crw->arp]) == 1)
			crw->arp++;
		else
			call_simple_error(CHA_SET);
	}
}
