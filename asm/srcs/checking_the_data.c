/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_the_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 02:01:30 by denis             #+#    #+#             */
/*   Updated: 2020/10/04 22:26:36 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_size(t_op *op)
{
	int	size;
	int	i;

	size = 1;
	size += (op->octet != 0);
	i = 0;
	while (i < 3)
	{
		if (op->argutype[i] < 0)
			call_error(ER_N_AR);
		if (op->argutype[i] == 1 &&
			(op->argu[i] < 1 || op->argu[i] > 99))
			exit(!!ft_printf_fd(2, "ERROR: invalid registry value for op. %d\n",
				op->u_id));
		if (op->argutype[i] == 1)
			size++;
		if (op->argutype[i] == 2)
			size += T_DIR_SIZE[op->inst_id];
		else if (op->argutype[i] == 3)
			size += 2;
		i++;
	}
	if (size != op->size)
		exit(!!ft_printf_fd(2, "ERROR: wrong opsize, op. %d\n", op->u_id));
}

static void	check_labels(t_op *oper, t_lbl *label, int arg_nr)
{
	t_lbl		*tmp;

	tmp = label;
	if ((oper->is_arg_label_or_not[arg_nr] != 0 && oper->argutype[arg_nr] > 0) ||
		(oper->is_arg_label_or_not[arg_nr] == 0 && oper->argutype[arg_nr] < 0))
		exit(!!ft_printf_fd(2, "ERROR: incompatible arg-label combination\n"));
	else if (oper->argutype[arg_nr] < 0)
		oper->argutype[arg_nr] = -oper->argutype[arg_nr];
	while (tmp != NULL && tmp->u_id != oper->is_arg_label_or_not[arg_nr])
		tmp = tmp->next;
	if (tmp == NULL)
		exit(!!ft_printf_fd(2, "ERROR: label %d for op.%d not found\n",
			oper->is_arg_label_or_not[arg_nr], oper->u_id));
	if (tmp->pos == -1)
		exit(!!ft_printf_fd(2, "ERROR: label %s not found\n", tmp->name));
	oper->argu[arg_nr] = tmp->pos - oper->pos;
	if (oper->argutype[arg_nr] == 1 &&
		(oper->argu[arg_nr] > 99 || oper->argu[arg_nr] < 1))
		exit(!!ft_printf_fd(2, "ERROR: operation %d arg %d is reg %d - invalid",
			oper->u_id, arg_nr, oper->argu[arg_nr]));
}


static void	check_arguments(t_op *oper, t_lbl *labels)
{
	int		i;
	int		args_qty;
	int		allowed;

	i = MAX_ARGS;
	args_qty = ARGS_QTY[oper->inst_id];
	allowed = ARGS_TYPES[oper->inst_id];
	while (i > args_qty)
	{
		i--;
		if (oper->argutype[i] != 0)
			exit(!!ft_printf_fd(2, "ERROR: too many arguments for instr nr %d",
				oper->u_id));
		allowed /= 10;
	}
	while (i > 0)
	{
		i--;
		if (oper->argutype[i] < 0 || oper->is_arg_label_or_not[i] != 0)
			check_labels(oper, labels, i);
		if ((allowed % 10) != 0 && ((allowed % 10) & (oper->argutype[i] +
										(oper->argutype[i] > 2))) == 0)
			call_error(ARG_INV);
		allowed /= 10;
	}
}

static void	check_op(t_crw *crwdata, t_op  *oper)
{
	if (oper->inst_id > 16 || oper->inst_id < 1)
		exit(!!ft_printf_fd(2, "ERROR: instr. id %d for op. nr %d is invalid\n",
			oper->inst_id, oper->u_id));
	if (oper->u_id < 1)
		exit(!!ft_printf_fd(2, "ERROR: id for operation nr %d is invalid\n",
			oper->u_id));
	if (oper->next && oper->u_id - oper->next->u_id != -1)
		exit(!!ft_printf_fd(2, "ERROR: op. %d enumeration sequence is wrong\n",
			oper->u_id));
	if (oper->pos >= crwdata->total_size)
		exit(!!ft_printf_fd(2, "ERROR: operation nr %d position is wrong\n",
				oper->u_id, oper->pos,
		crwdata->total_size));
	oper->octet *= OCTAL[oper->inst_id];
}

void        checking_the_data(t_crw *crwdata)
{
    t_op  *oper;
    t_lbl *lbl;

	if (!crwdata->name)
		exit(!!ft_printf_fd(2, "ERROR: Champ name is not set\n"));
	if (!crwdata->cmnt)
		exit(!!ft_printf_fd(2, "ERROR: Champ comment is not set\n"));
	if (!crwdata->op)
		exit(!!ft_printf_fd(2, "ERROR: Champ has no instructions\n"));
	if (ft_strlen(crwdata->name) > 128)
		exit(!!ft_printf_fd(2, "ERROR: .name too long (%d) > max len (%d)\n",
			ft_strlen(crwdata->name), 128));
	if (ft_strlen(crwdata->cmnt) > 2048)
		exit(!!ft_printf_fd(2, "ERROR: .coment too long (%d) > max len (%d)\n",
			ft_strlen(crwdata->cmnt), 2048));
	oper = crwdata->op;
	while (oper)
	{
		check_op(crwdata, oper);
		lbl = crwdata->label;
		check_arguments(oper, lbl);
		check_size(oper);
		oper = oper->next;
	}
}