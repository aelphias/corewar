/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:32:53 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/03/06 12:32:53 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_memjoin(void const *src1, void const *src2,
		size_t size1, size_t size2)
{
	void	*ptr;
	size_t	len;

	if (src1 && src2)
	{
		len = size1 + size2;
		if (!(ptr = (char*)malloc((1 + len) * sizeof(*src1))))
			return (NULL);
		ft_memcpy(ptr, src1, size1);
		ft_memcpy(ptr + size1, src2, size2);
		return (ptr);
	}
	return (NULL);
}
