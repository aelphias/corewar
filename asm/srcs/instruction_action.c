/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 21:50:43 by denis             #+#    #+#             */
/*   Updated: 2020/09/28 01:12:30 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			is_an_instruction_or_not_2(char *s)
{
	if (ft_strcmp(s, "zjmp\0") == 0)
		return (9);
	else if (ft_strcmp(s, "ldi\0") == 0)
		return (10);
	else if (ft_strcmp(s, "sti\0") == 0)
		return (11);
	else if (ft_strcmp(s, "fork\0") == 0)
		return (12);
	else if (ft_strcmp(s, "lld\0") == 0)
		return (13);
	else if (ft_strcmp(s, "lldi\0") == 0)
		return (14);
	else if (ft_strcmp(s, "lfork\0") == 0)
		return (15);
	else if (ft_strcmp(s, "aff\0") == 0)
		return (16);
	else
		return (0);
}

int					is_an_instruction_or_not(char *s)
{
	if (ft_strcmp(s, "live\0") == 0)
		return (1);
	else if (ft_strcmp(s, "ld\0") == 0)
		return (2);
	else if (ft_strcmp(s, "st\0") == 0)
		return (3);
	else if (ft_strcmp(s, "add\0") == 0)
		return (4);
	else if (ft_strcmp(s, "sub\0") == 0)
		return (5);
	else if (ft_strcmp(s, "and\0") == 0)
		return (6);
	else if (ft_strcmp(s, "or\0") == 0)
		return (7);
	else if (ft_strcmp(s, "xor\0") == 0)
		return (8);
	else
		return (is_an_instruction_or_not_2(s));
}

static t_op	*set_instruction(t_crw *crwdata, int inst_id, int op_id)
{
	t_op *op;

	op = crwdata->op;
	while (op != NULL && op->next != NULL)
	{
		op_id++;
		op = op->next;
	}
	if (op == NULL)
	{
		crwdata->op = (t_op*)ft_memalloc(sizeof(t_op));
		op = crwdata->op;
	}
	else
	{
		op->next = (t_op*)ft_memalloc(sizeof(t_op));
		op_id++;
		op = op->next;
	}
	op->inst_id = inst_id;
	op->u_id = op_id;
	op->pos = crwdata->total_size;
	return (op);
}

static void			set_op_size(t_op *op)
{
	int		i;

	i = 0;
	op->size = 1;
	while (i < MAX_ARGS)
	{
		op->size += op->arg_size[i];
		i++;
	}
	op->size += (op->octet != 0);
}

int					get_inst(t_crw *crwdata, char **tmp,
								int inst_id, int tmp_len)
{
	t_op *op;

	if (inst_id == 0)
		return (0);
	if (tmp_len < 2)
		exit(!!ft_printf_fd(2, "ERROR: no arguments at line %d\n",
					crwdata->line_q));
	op = set_instruction(crwdata, inst_id, 1);
	get_argz(op, &tmp[1], tmp_len - 1, crwdata);
	set_op_size(op);
	crwdata->total_size += op->size;
	return (op->pos);
}
