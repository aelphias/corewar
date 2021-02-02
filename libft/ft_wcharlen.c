/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:20:33 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/21 17:20:34 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlens(unsigned str)
{
	if (str < 0x80)
		return (1);
	else if (str < 0x800)
		return (2);
	else if (str < 0x10000)
		return (3);
	return (4);
}
