/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:16:18 by jigglyp           #+#    #+#             */
/*   Updated: 2021/01/11 11:09:53 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		spcs(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static char		*recrd(char *s1, char *s2, size_t tmp, size_t i)
{
	size_t j;

	j = 0;
	while (tmp <= i)
		s1[j++] = s2[tmp++];
	s1[j] = '\0';
	return (s1);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	size_t	tmp;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	while (spcs(s[i]) && s[i])
		i++;
	tmp = i;
	if (s[i] != '\0')
	{
		while (s[i])
			i++;
		i = i - 1;
		while (spcs(s[i]) && i > -1)
			i--;
	}
	if (!(str = (char *)malloc(((i - tmp) + 2) * sizeof(char))))
		return (NULL);
	if (i < 0)
		return (str);
	recrd(str, (char *)s, tmp, i);
	return (str);
}
