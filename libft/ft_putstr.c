/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:28:59 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/11 19:29:00 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr(char const *s)
{
	size_t i;

	i = 0;
	if (!s)
		return ;
	while ((char)s[i])
	{
		ft_putchar((char)s[i]);
		i++;
	}
}
