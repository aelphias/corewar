/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:53:03 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/01 20:08:39 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*add_spaces(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = (char*)ft_memalloc(sizeof(char) * 2 * (ft_strlen(str) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%' || (i > 0 && str[i - 1] == ',')
			|| (i > 1 && str[i - 1] == ':'
				&& ft_strchr(LABEL_CHARS, str[i - 2])))
		{
			tmp[j] = ' ';
			j++;
		}
		tmp[j] = str[i];
		j++;
		i++;
	}
	return (tmp);
}

/*
** подсч>ёт числа слов
*/

int			wordcount(char *str, int c)
{
	int		wc;
	int		i;

	wc = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] > c && (str[i + 1] <= c || str[i + 1] == 127))
			wc++;
		i++;
	}
	return (wc);
}

void		fill_word(char const *s, char *word, int b, int e)
{
	int		i;

	i = 0;
	while (b < e)
	{
		word[i] = s[b];
		b++;
		i++;
	}
}

/*
** заполняем массив слов
*/

char		**fillaw(char **aw, char *str, int c)
{
	int		i[4];

	i[0] = -1;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	while (str[++i[0]] != '\0')
	{
		if (str[i[0]] <= c || str[i[0]] == '\0')
			i[2] = i[0] + 1;
		if (str[i[0]] > c && (str[i[0] + 1] == 127
			|| str[i[0] + 1] <= c))
		{
			i[3] = i[0] + 1;
			aw[i[1]] = (char*)ft_memalloc(sizeof(char) * (i[3] - i[2] + 1));
			fill_word(str, aw[i[1]], i[2], i[3]);
			i[1]++;
		}
	}
	aw[i[1]] = 0;
	return (aw);
}

char		**split_string(char *str)
{
	char	**aw;
	int		nw;

	if (str)
	{
		nw = wordcount(str, 32);
		aw = (char**)ft_memalloc(sizeof(char*) * (nw + 1));
		if (aw)
			return (fillaw(aw, str, 32));
	}
	return (0);
}
