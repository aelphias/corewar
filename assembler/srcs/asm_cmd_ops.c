/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_cmd_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:59:22 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/26 16:41:47 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				is_cmnd(char *word)
{
	int			i;

	i = 0x00;
	while (i++ < 0x10)
	{
		if (ft_strcmp(g_op[i].name, word) == 0)
			return (g_op[i].code);
	}
	return (0);
}

void			count_cmnd_size(t_cmnd *cmnd, int id_cm)
{
	int			i;

	i = 0;
	cmnd->size += 1 + g_op[id_cm - 1].args_types_code;
	while (i < 3)
	{
		cmnd->size += cmnd->argument_size[i];
		i++;
	}
}

t_cmnd			*add_cmnd(t_crw *crw, int id_cm)
{
	t_cmnd		*cmnd;
	int			id_lst;

	id_lst = 1;
	cmnd = crw->cmnd;
	while (cmnd != NULL && cmnd->next != NULL)
	{
		id_lst++;
		cmnd = cmnd->next;
	}
	if (cmnd == NULL)
	{
		crw->cmnd = (t_cmnd *)ft_memalloc(sizeof(t_cmnd));
		cmnd = crw->cmnd;
	}
	else
	{
		cmnd->next = (t_cmnd*)ft_memalloc(sizeof(t_cmnd));
		id_lst++;
		cmnd = cmnd->next;
	}
	cmnd->id = id_lst;
	cmnd = init_cm_lst(cmnd, id_cm, crw);
	return (cmnd);
}

void			check_cmnd(t_crw *crw, char **arr_words,
									int id_cm, int nb_words)
{
	t_cmnd 		*cmnd;

	if ((crw->if_name_exist == 0) || (crw->if_cmnt_exist == 0))
		call_simple_error("ERROR: comment of champion is missing "
							"at the beginning of the file\n");
	if (nb_words < 2)
		call_simple_error("ERROR: no arguments at line\n");
	if (id_cm != 0)
	{
		cmnd = add_cmnd(crw, id_cm);
		get_args(cmnd, &arr_words[1], nb_words - 1, crw);
		count_cmnd_size(cmnd, id_cm);
		crw->arp += ft_strlen(crw->string) - 1;
		crw->size_code += cmnd->size;
	}
}