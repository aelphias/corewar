/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:50:29 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	points(char *string, int c)
{
	while (*string)
		write(1, string++, 1);
	ft_putnbr(c);
	write(1, "m", 1);
}

int		init_col(char **f, int color, int len)
{
	points("\x1b[", color);
	(*f) = (*f + len);
	return (0);
}

int		without_color(char **f)
{
	(*f)++;
	return (write(1, "{", 1));
}

int		colorset(char **fmt)
{
	if (ft_strncmp((const char *)*fmt, "{red}", 5) == 0)
		return (init_col(fmt, 91, 5));
	else if (ft_strncmp((const char *)*fmt, "{green}", 7) == 0)
		return (init_col(fmt, 92, 7));
	else if (ft_strncmp((const char *)*fmt, "{yellow}", 8) == 0)
		return (init_col(fmt, 93, 8));
	else if (ft_strncmp((const char *)*fmt, "{blue}", 6) == 0)
		return (init_col(fmt, 94, 6));
	else if (ft_strncmp((const char *)*fmt, "{magenta}", 9) == 0)
		return (init_col(fmt, 95, 9));
	else if (ft_strncmp((const char *)*fmt, "{cyan}", 6) == 0)
		return (init_col(fmt, 96, 6));
	else if (ft_strncmp((const char *)*fmt, "{white}", 7) == 0)
		return (init_col(fmt, 97, 7));
	else if (ft_strncmp((const char *)*fmt, "{eoc}", 5) == 0)
		return (init_col(fmt, 0, 5));
	else
		return (without_color(fmt));
}
