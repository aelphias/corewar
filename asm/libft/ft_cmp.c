/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:41:11 by qweissna          #+#    #+#             */
/*   Updated: 2018/12/22 17:16:34 by qweissna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmp(int a, int b)
{
	if ((a - b) > 0 || (a - b) < 0)
		return (a - b);
	else
		return (0);
}
