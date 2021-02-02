/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:56:48 by kcharlet          #+#    #+#             */
/*   Updated: 2021/02/01 14:45:41 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		exec(t_car *car, uint8_t *arena, t_op *op, t_vm *vm)
{
	car->dir_size_status = op->dir_size_status;
	car->is_type_code = op->is_type_code;
	if (get_args_type(car, arena, op))
	{
		walk(car, 1);
		if (car->op_code == 1)
			op_live(car, arena, vm);
		else
			choose_1(car, arena);
	}
	else
	{
		if (car->is_type_code)
			car->pos = update_pos(car->pc + move(car) + 2);
		else
			car->pos = update_pos(car->pc + move(car) + 1);
		car->pc = car->pos;
	}
	ft_bzero(car->arg_type, sizeof(car->arg_type));
}

t_bool		valid_op(t_car *car)
{
	if (car->op_code >= 1 && car->op_code <= 16)
		return (true);
	return (false);
}

void		before_exec(t_car *car, uint8_t *arena, t_vm *vm)
{
	t_op	*op;

	if (valid_op(car))
	{
		op = &g_op[MINUS_ONE(car->op_code)];
		exec(car, arena, op, vm);
	}
	else
	{
		car->pos = update_pos(car->pos + 1);
		car->pc = car->pos;
	}
}

void		cycle(t_car **head_car, uint8_t *arena, t_vm *vm)
{
	t_op	*op;
	t_car	*car;

	car = NULL;
	car = (*head_car);
	while (car)
	{
		if (car->wait == 0)
		{
			car->op_code = get_byte(arena, car);
			if (valid_op(car))
			{
				op = &g_op[MINUS_ONE(car->op_code)];
				car->wait = op->cycles_wait;
			}
		}
		if (car->wait > 0)
			car->wait--;
		if (car->wait == 0)
			before_exec(car, arena, vm);
		if (!(car->next) && (car->wait != 0))
			break ;
		car = car->next;
	}
}

void		game(t_car **head_car, uint8_t *arena, t_vm *vm)
{
	while (vm->car_count)
	{
		vm->cycles++;
		cycle(head_car, arena, vm);
		if (vm->cycles_to_die <= 0
		|| ((vm->cycles - vm->last_check_cycle) == vm->cycles_to_die))
			check(vm, head_car);
		if (vm->cycles == vm->dump)
		{
			dump(arena);
			exit(0);
			return ;
		}
	}
	ft_printf("Player %d, won !\n", vm->winner_id);
}
