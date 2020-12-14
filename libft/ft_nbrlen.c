/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:33:54 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/07/20 23:05:10 by denis            ###   ########.fr       */
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
