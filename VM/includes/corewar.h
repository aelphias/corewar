/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/13 16:09:56 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "libft.h"
#include "../includes/op.h"
#include "errors.h"

typedef enum { false, true }	bool;

# define MINUS_ONE(X)			((X) - 1)

typedef struct					s_plr
{
	int							id;
	int							n_id;
	uint8_t						*name;
	uint8_t						*cmnt;
	unsigned int				pos; 
	unsigned int				codesize;
	uint8_t						*code;
	struct s_plr				*head;
	struct s_plr				*next;
}								t_plr;

typedef struct					s_vm
{
	unsigned int				plr_count;
	unsigned int				lived;  // количество выполненных операий live за c_t_d
	int							car_count;
	long int					check_count;
	long int					cycles;
	long int					cycles_to_die;
	long int					cycles_aff_check;
	int							n;
	int							dump;
	t_plr						*hd_plrs;
	int							winner_id;
}								t_vm;

typedef struct					s_car
{
	bool						carry;
	unsigned int				pos;
	int							reg[REG_NUMBER];
	int							id;
	bool						is_type_code;
	int							arg[3];
	int							arg_type[3];
	int							parent_car;
	unsigned int				last_live_cycle;  // цикл, на котором последний раз вполнилась операция live
	unsigned int				op_code;
	unsigned int				wait;
	unsigned int				pc;
	unsigned int				dir_size_status;
	unsigned int				step;
	struct s_car				*next;
}								t_car;

typedef struct		s_op
{
	char			*name;
	unsigned int	code;
	unsigned int	args_amount;
	bool			is_type_code; 
	unsigned int	args_types[3];
	bool			modify_carry;
	unsigned int	dir_size_status;
	unsigned int	cycles_wait;
	void			(*func)(t_car *, uint8_t *, t_vm *);
}					t_op;

/*
**	init car
*/

void							init_car(t_plr *plr, t_car **head, int pos);
t_car							*make_car(t_plr *plr, t_vm *vm);
int								plr_count(t_plr *head);

/*
**	init arena 
*/

void							fill_arena(t_plr *plr, t_vm *vm, uint8_t *arena);
void							ft_copy_code(uint8_t *dst, uint8_t *src, int codesize);

/*
**	инициализация t_vm, t_op
*/

void							init_vm(t_vm *vm);


/*
**	parse 
*/


void 				check_flags(int argc, char **argv, t_vm *vm);
void 				check_n_flags(int argc, char **argv, t_plr *plr);
t_plr	 			*ft_parse(int argc, char **argv);




/*
**	utils
*/

unsigned int		update_pos(unsigned int pos);
uint8_t				get_byte(uint8_t *arena, unsigned int pos);
void				dump(uint8_t *arena);
void				introduce_plrs(t_plr *plr);
int					arena_loop(uint8_t *arena, uint32_t coord);
int					is_num(char *str);
int					checkdotcor(char *argv);
void				print_error(int num_error);

/*
**	зачистка всего
*/

void							ft_free_vm(t_vm *vm);
void							ft_free_plr(t_plr *plr);

/*
**	game
*/

void				game(t_car **car, uint8_t *arena, t_vm *vm);
void				cycle(t_car **head_car, uint8_t *arena, t_vm *vm);
void				check(t_vm *vm, t_car **head_car);
void				bury_car(t_vm *vm, t_car **head_car);
void				check_winner(t_vm *vm);
void				get_args_type(t_car *car, unsigned char *arena, t_op *op);
void				write_arg_type(int arg_type, t_car *car, t_op *op, int ind);
void				exec(t_car *car, uint8_t *arena, t_op *op, t_vm *vm);
int					get_arg(t_vm *vm, t_car *car, int arg_number, uint8_t *arena);




/*
**	void	operations(t_car *car, uint8_t *arena, void (**func)(t_car *, uint8_t *));
**	void	no();
*/

void							op_live(t_car *car, uint8_t *arena, t_vm *vm);
void							op_ld(t_car *car, uint8_t *arena, t_vm *vm);
void							op_st(t_car *car, uint8_t *arena, t_vm *vm);
void							op_add(t_car *car, uint8_t *arena, t_vm *vm);
void							op_sub(t_car *car, uint8_t *arena, t_vm *vm);
void							op_and(t_car *car, uint8_t *arena, t_vm *vm);
void							op_or(t_car *car, uint8_t *arena, t_vm *vm);
void							op_xor(t_car *car, uint8_t *arena, t_vm *vm);
void							op_zjmp(t_car *car, uint8_t *arena, t_vm *vm);
void							op_ldi(t_car *car, uint8_t *arena, t_vm *vm);
void							op_sti(t_car *car, uint8_t *arena, t_vm *vm);
void							op_fork(t_car *car, uint8_t *arena, t_vm *vm);
void							op_lld(t_car *car, uint8_t *arena, t_vm *vm);
void							op_lldi(t_car *car, uint8_t *arena, t_vm *vm);
void							op_lfork(t_car *car, uint8_t *arena, t_vm *vm);
void							op_aff(t_car *car, uint8_t *arena, t_vm *vm);

/*
**	testing
*/

void							test(t_vm *vm, t_plr *plr);
void							print_list(t_plr *plr);
void							print_list_car(t_car *car);

/*
**	alfa version op_tab
*/

static uint8_t			g_arg_code[3] = {
	T_REG,
	T_DIR,
	T_IND
};

static t_op					g_op[16] = {
	{
		.name = "live",
		.code = 1,
		.args_amount = 1,
		.is_type_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.dir_size_status = 4,
		.cycles_wait = 10,
		.func = &op_live
	},
	{
		.name = "ld",
		.code = 2,
		.args_amount = 2,
		.is_type_code = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = true,
		.dir_size_status = 4,
		.cycles_wait = 5,
		.func = &op_ld
	},
	{
		.name = "st",
		.code = 3,
		.args_amount = 2,
		.is_type_code = true,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.modify_carry = false,
		.dir_size_status = 4,
		.cycles_wait = 5,
		.func = &op_st
	},
	{
		.name = "add",
		.code = 4,
		.args_amount = 3,
		.is_type_code = true,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = true,
		.dir_size_status = 4,
		.cycles_wait = 10,
		.func = &op_add
	},
	{
		.name = "sub",
		.code = 5,
		.args_amount = 3,
		.is_type_code = true,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = true,
		.dir_size_status = 4,
		.cycles_wait = 10,
		.func = &op_sub
	},
	{
		.name = "and",
		.code = 6,
		.args_amount = 3,
		.is_type_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.dir_size_status = 4,
		.cycles_wait = 6,
		.func = &op_and
	},
	{
		.name = "or",
		.code = 7,
		.args_amount = 3,
		.is_type_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.dir_size_status = 4,
		.cycles_wait = 6,
		.func = &op_or
	},
	{
		.name = "xor",
		.code = 8,
		.args_amount = 3,
		.is_type_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.dir_size_status = 4,
		.cycles_wait = 6,
		.func = &op_xor
	},
	{
		.name = "zjmp",
		.code = 9,
		.args_amount = 1,
		.is_type_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.dir_size_status = 2,
		.cycles_wait = 20,
		.func = &op_zjmp
	},
	{
		.name = "ldi",
		.code = 10,
		.args_amount = 3,
		.is_type_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = false,
		.dir_size_status = 2,
		.cycles_wait = 25,
		.func = &op_ldi
	},
	{
		.name = "sti",
		.code = 11,
		.args_amount = 3,
		.is_type_code = true,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = false,
		.dir_size_status = 2,
		.cycles_wait = 25,
		.func = &op_sti
	},
	{
		.name = "fork",
		.code = 12,
		.args_amount = 1,
		.is_type_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.dir_size_status = 2,
		.cycles_wait = 800,
		.func = &op_fork
	},
	{
		.name = "lld",
		.code = 13,
		.args_amount = 2,
		.is_type_code = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = true,
		.dir_size_status = 4,
		.cycles_wait = 10,
		.func = &op_lld
	},
	{
		.name = "lldi",
		.code = 14,
		.args_amount = 3,
		.is_type_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = true,
		.dir_size_status = 2,
		.cycles_wait = 50,
		.func = &op_lldi
	},
	{
		.name = "lfork",
		.code = 15,
		.args_amount = 1,
		.is_type_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.dir_size_status = 2,
		.cycles_wait = 1000,
		.func = &op_lfork
	},
	{
		.name = "aff",
		.code = 16,
		.args_amount = 1,
		.is_type_code = true,
		.args_types = {T_REG, 0, 0},
		.modify_carry = false,
		.dir_size_status = 4,
		.cycles_wait = 2,
		.func = &op_aff
	}
};

#endif
