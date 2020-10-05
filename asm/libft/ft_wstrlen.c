/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:20:10 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/29 18:51:29 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(unsigned *s)
{
	size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len += ft_wcharlens(*s);
		++s;
	}
	return (len);
}

size_t		ft_wstrlen_wch(const wchar_t *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
