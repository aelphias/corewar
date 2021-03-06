/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:41:11 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/24 18:33:13 by kcharlet         ###   ########.fr       */
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
