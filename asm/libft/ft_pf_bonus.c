/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:18:02 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/02/21 17:11:25 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_base(t_printf *t_print)
{
	int	base;

	t_print->base = 10;
	if (*t_print->str == '_' && ft_isdigit(*(++t_print->str)))
	{
		base = ft_atoi(t_print->str);
		if (base && !(base % 2) && base <= 34)
		{
			t_print->base = base;
			while (ft_isdigit(*t_print->str))
				t_print->str++;
		}
	}
}

void	parse_width_spec(t_printf *lstprf)
{
	lstprf->str++;
	if ((lstprf->str) && ft_isdigit(*lstprf->str))
	{
		lstprf->width = va_arg(lstprf->args, int);
		lstprf->width = ft_atoi(lstprf->str);
		while (ft_isdigit(*lstprf->str))
			lstprf->str++;
		lstprf->str--;
	}
	else
	{
		lstprf->str--;
		lstprf->width = va_arg(lstprf->args, int);
	}
	lstprf->str++;
}
