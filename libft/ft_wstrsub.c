/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:19:58 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/21 17:19:59 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t *s, unsigned start, unsigned len)
{
	wchar_t		*str;
	unsigned	i;

	if (!(str = ft_memalloc(sizeof(wchar_t) * (len + 1))))
		return (NULL);
	i = 0;
	while (ft_wcharlens(s[i + start]) < len)
	{
		str[i] = s[i + start];
		i += ft_wcharlens(str[i]);
	}
	str[i] = '\0';
	return (str);
}
