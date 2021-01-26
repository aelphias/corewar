/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_label_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:57:55 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 17:20:49 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				is_label(char *word)
{
	int			len;

	len = (int)ft_strlen(word);
	if (len > 1 && word[len - 1] == LABEL_CHAR)
	{
		len -= 2;
		while (len >= 0)
		{
			if (ft_strchr(LABEL_CHARS, word[len]) == NULL)
				return (0);
			len--;
		}
		return (1);
	}
	return (0);
}

void			init_new_label(t_lbl **tmp, char *word, int id)
{
	tmp[0] = (t_lbl*)ft_memalloc(sizeof(t_lbl));
	tmp[0]->name = ft_strdup(word);
	tmp[0]->id = id;
	tmp[0]->pos = -1;
}

t_lbl			*labadd(t_lbl **label, char *word)
{
	int			id;
	int			len;
	t_lbl		*res;
	t_lbl		*tmp;

	len = ft_strlen(word);
	id = 1;
	res = *label;
	if (len > 0)
		word[len - 1] = '\0';
	while (res != NULL && res->next != NULL && ft_strcmp(res->name, word) != 0)
	{
		id++;
		res = res->next;
	}
	if (res != NULL && ft_strcmp(res->name, word) == 0)
		return (res);
	if (res != NULL)
		id++;
	init_new_label(&tmp, word, id);
	if (res == NULL)
		*label = tmp;
	else
		res->next = tmp;
	return (tmp);
}

void			check_label(t_crw *parser, char **arr_words, int nb_words)
{
	t_lbl		*label;

	if ((parser->if_name_exist == 0) || (parser->if_cmnt_exist == 0))
		call_simple_error("ERROR: name/comment of champion is missing at the beginning of the file\n");
	label = labadd(&parser->lbl, arr_words[0]);
	if (label->pos != -1)
		call_simple_error("ERROR: duplicate label\n");
	if (parser->size_code == 0)
		label->pos = 0;
	else
		label->pos = parser->last_cmnd->pos +
							parser->last_cmnd->size;
	if (nb_words > 1 && is_label(arr_words[1]))
		check_label(parser, &arr_words[1], nb_words - 1);
	else if (nb_words > 1 && is_cmnd(arr_words[1]) > 0)
		check_cmnd(parser, &arr_words[1],
		is_cmnd(arr_words[1]), nb_words - 1);
	else if (nb_words > 1)
		call_simple_error("ERROR: invalid string\n");
	else
		parser->arp += ft_strlen(parser->string) - 1;
}
