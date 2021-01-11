/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:26:54 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/11 19:26:56 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] - s2[i] == 0 && i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		i++;
	}
	if (s1[i - 1] - s2[i - 1] == 0 && i == n)
		return (1);
	return (0);
}
