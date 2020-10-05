/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 21:53:45 by denis             #+#    #+#             */
/*   Updated: 2020/09/28 01:12:30 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_label(char *s)
{
	int		i;
	int		len;

	if (!s)
		exit(!!ft_printf_fd(2, "ERROR: last label points to nothing\n"));
	len = (int)ft_strlen(s);
	if (len < 2 || s[len - 1] != ':')
		return (0);
	i = 0;
	while (i < len - 1)
	{
		if (ft_strchr(LABEL_CHARS, s[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

static void	set_new_label(t_lbl **tmp, char *s, int id)
{
	tmp[0] = (t_lbl*)ft_memalloc(sizeof(t_lbl));
	tmp[0]->name = ft_strdup(s);
	tmp[0]->u_id = id;
	tmp[0]->pos = -1;
}

t_lbl		*set_lbl(t_lbl **label, char *s)
{
	t_lbl		*res;
	t_lbl		*tmp;
	int			id;

	id = 1;
	res = *label;
	if (ft_strlen(s) > 0)
		s[ft_strlen(s) - 1] = 0;
	while (res != NULL && res->next != NULL && ft_strcmp(res->name, s) != 0)
	{
		id++;
		res = res->next;
	}
	if (res != NULL && ft_strcmp(res->name, s) == 0)
		return (res);
	if (res != NULL)
		id++;
	set_new_label(&tmp, s, id);
	if (res == NULL)
		*label = tmp;
	else
		res->next = tmp;
	return (tmp);
}

static void	get_next(t_lbl *label, t_crw *data)
{
	char	*s;

	while (get_clean_string(data, &s) && ft_strlen(s) < 1)
	{
		data->line_q++;
		free_str_arr(&s, NULL, 1);
	}
	data->line_q++;
	label->pos = get_lbls_instr(data, s);
	free_str_arr(&s, NULL, 1);
}

int			get_lbl(t_crw *data, char **tmp, int tmp_len)
{
	t_lbl	*label;
	int		label_pos;

	label = set_lbl(&data->label, tmp[0]);
	label_pos = label->pos;
	if (tmp_len > 1 && is_label(tmp[1]))
		label->pos = get_lbl(data, &tmp[1], tmp_len - 1);
	else if (tmp_len > 1 && is_an_instruction_or_not(tmp[1]))
		label->pos = get_inst(data, &tmp[1],
								is_an_instruction_or_not(tmp[1]), tmp_len - 1);
	else if (tmp_len > 1)
		exit(!!ft_printf_fd(2, "ERROR: %s at line %d\n",
				tmp[1], data->line_q));
	else if (tmp_len < 2)
		get_next(label, data);
	label->pos = (label_pos == -1) ? label->pos : label_pos;
	return (label->pos);
}

int			get_lbls_instr(t_crw *data, char *s)
{
	char		**tmp;
	char		*space_string;
	int			i;
	int			res;

	space_string = add_spaces(&s);
	tmp = ft_strsplit_whitespace(space_string);
	free_str_arr(&space_string, NULL, 1);
	i = 0;
	while (tmp[i])
		i++;
	res = 0;
	if (is_label(tmp[0]))
		res = get_lbl(data, tmp, i);
	else if (is_an_instruction_or_not(tmp[0]) != 0)
		res = get_inst(data, tmp, is_an_instruction_or_not(tmp[0]), i);
	else if (s[0] != '#')
		exit(!!ft_printf_fd(2, "ERROR: couldn't read line %d (%s)\n",
				data->line_q, s));
	free_str_arr(NULL, &tmp, 0);
	return (res);
}
