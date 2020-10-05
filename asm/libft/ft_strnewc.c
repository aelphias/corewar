/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:16:25 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/10/24 19:16:27 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewc(size_t size, char c)
{
	char	*dst;
	size_t	i;

	if (size + 1 < size)
		return (NULL);
	i = 0;
	if (!(dst = (char *)malloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		dst[i] = c;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
