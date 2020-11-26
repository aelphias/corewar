/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_second.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:44:10 by denis             #+#    #+#             */
/*   Updated: 2020/09/05 19:14:19 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_first(char **s1, char const *s2)
{
	char	*ptr;
	int		len;

	if (s1 && s2 && *s1)
	{
		len = ft_strlen(s2) + ft_strlen(*s1);
		if (!(ptr = (char*)malloc((1 + len) * sizeof(*ptr))))
			return (NULL);
		ft_strcpy(ptr, *s1);
		ft_strcat(ptr, s2);
		ft_memdel((void**)s1);
		return (ptr);
	}
	return (NULL);
}

char	*ft_strjoin_free_second(char const *s1, char **s2)
{
	char	*ptr;
	int		len;

	if (s1 && s2 && *s2)
	{
		len = ft_strlen(*s2) + ft_strlen(s1);
		if (!(ptr = (char*)malloc((1 + len) * sizeof(*ptr))))
			return (NULL);
		ft_strcpy(ptr, s1);
		ft_strcat(ptr, *s2);
		ft_memdel((void**)s2);
		return (ptr);
	}
	return (NULL);
}
