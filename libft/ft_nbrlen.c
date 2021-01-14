/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:17 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 13:35:18 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

int	ft_unbrlen(uintmax_t nbr, int base)
{
	int len;

	len = 1;
	while (nbr /= base)
		len++;
	return (len);
}

int	ft_nbrlen(intmax_t nbr)
{
	int len;

	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}
