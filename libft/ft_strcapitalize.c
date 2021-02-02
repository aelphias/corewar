/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:36:40 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		ft_up_char(char c)
{
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return (c);
}

char		ft_low_char(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

int			ft_is_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char		*ft_strcapitalize(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str)
	{
		if (ft_is_letter(*str))
		{
			*str = ft_up_char(*str);
			++str;
			while (ft_is_letter(*str))
			{
				*str = ft_low_char(*str);
				++str;
			}
		}
		++str;
	}
	return (tmp);
}
