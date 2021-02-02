/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:27:24 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/21 17:27:26 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strctrim(char const *s, char c)
{
	unsigned int	i;
	size_t			len;
	char			*mem;

	i = 0;
	while ((s[i]) == c)
		++i;
	len = ft_strlen(s) - 1;
	while (len > i && s[len] == c)
		len--;
	if (len < i)
		return (mem = ft_strdup(""));
	return (mem = ft_strsub(s, i, len - (size_t)i + 1));
}
