/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:25:12 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wds(char *s, char c)
{
	int		words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

char		*ft_leng(char *s, char c)
{
	char		*l;

	l = s;
	while (*s && *s != c)
		s++;
	*s = '\0';
	return (ft_strdup(l));
}

void		free_me(char **str, int i)
{
	while (i >= 0)
	{
		ft_strdel(&(str[i]));
		i--;
	}
	free(*str);
}

char		**ft_split(char *s, char c, int arr)
{
	char	**str;
	int		i;
	char	*s1;

	i = 0;
	if ((str = (char **)ft_memalloc(sizeof(char *) * (arr + 1))))
	{
		while (i < arr)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(s1 = ft_leng(s, c)))
				{
					free_me(str, i);
					return (NULL);
				}
				str[i++] = s1;
				s += (ft_strlen(s1) + 1);
			}
		}
		str[i] = NULL;
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	*s1;
	int		arr;

	if (!s || !(s1 = ft_strdup((char *)s)))
		return (NULL);
	arr = ft_wds(s1, c);
	str = ft_split(s1, c, arr);
	free(s1);
	return (str);
}
