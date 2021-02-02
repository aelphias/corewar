/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:20:21 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/21 17:20:22 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t const *s1)
{
	wchar_t	*s2;
	size_t	len;

	len = ft_wstrlen((unsigned *)s1) * sizeof(wchar_t);
	if (!s1 || !(s2 = (wchar_t *)ft_memalloc((sizeof(wchar_t) + len))))
		return (NULL);
	ft_memcpy(s2, s1, len);
	return (s2);
}
