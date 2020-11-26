/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:17:30 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/09/05 19:23:32 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int a, int b)
{
	int	c;

	if (a <= b)
		c = a;
	else
		c = b;
	return (c);
}
