/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:27:02 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/21 17:27:03 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** random function using memory address instead of the usual timestamp
*/

#include "libft.h"

int		ft_rand(int min, int max)
{
	int n;
	int	rng;

	n = (long)malloc(sizeof(long)) >> 1;
	n = (n < 0) ? -n : n;
	rng = 0;
	while (n >= 10)
	{
		rng += (n % 10);
		n /= 10;
	}
	rng = (rng % (max - min + 1)) + min;
	return (rng);
}
