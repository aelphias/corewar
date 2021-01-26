/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:53:03 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 18:56:40 by gjigglyp         ###   ########.fr       */
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

int			words_counter(char *str, int c)
{
	int		word_count;
	int		i;

	word_count = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] > c && (str[i + 1] <= c || str[i + 1] == 127))
			word_count++;
		i++;
	}
	return (word_count);
}

void		fill_word(char const *s, char *word, int start, int stop)
{
	int		i;

	i = 0;
	while (start < stop)
	{
		word[i] = s[start];
		start++;
		i++;
	}
}

char		**fill_arr_words(char **arr_words, char *str, int c)
{
	int		i;
	int		j;
	int		start;
	int		stop;

	i = -1;
	j = 0;
	start = 0;
	stop = 0;
	while (str[++i] != '\0')
	{
		if (str[i] <= c || str[i] == '\0')
			start = i + 1;
		if (str[i] > c && (str[i + 1] == 127
			|| str[i + 1] <= c))
		{
			stop = i + 1;
			arr_words[j] = (char*)ft_memalloc(sizeof(char) *
					(stop - start + 1));
			fill_word(str, arr_words[j], start, stop);
			j++;
		}
	}
	arr_words[j] = 0;
	return (arr_words);
}

char		**split_str(char *str)
{
	char	**arr_words;
	int		nb_words;

	if (str)
	{
		nb_words = words_counter(str, 32);
		arr_words = (char**)ft_memalloc(sizeof(char*) * (nb_words + 1));
		if (arr_words)
			return (fill_arr_words(arr_words, str, 32));
	}
	return (0);
}
