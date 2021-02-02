/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
/*   Updated: 2021/02/02 18:52:35 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../../libft/libft.h"
# include "../../includes/op.h"

# define ERR_USE		1
# define ERR_M_PLRS		2
# define ERR_MALLOC		3
# define ERR_PARSE		4
# define ERR_MAKE_CAR	5

typedef enum
{
	false,
	true
}	t_bool;

# define MINUS_ONE(X)			((X) - 1)

typedef struct					s_plr
{
	int							id;
	int							n_id;
	uint8_t						*name;
	uint8_t						*cmnt;
	long int					pos;
	unsigned int				codesize;
	uint8_t						*code;
	struct s_plr				*head;
	struct s_plr				*next;
}								t_plr;

/*
** t_vm - main struct keeps variables to count essentials for the game
** lived  - number of live operations performed per c_t_d
*/

typedef struct					s_vm
{
	int							plr_count;
	int							lived;
	int							car_count;
	long int					check_count;
	long int					cycles;
	long int					cycles_to_die;
	long int					cycles_aff_check;
	int							n;
	int							dump;
	t_plr						*hd_plrs;
	int							winner_id;
	int							last_check_cycle;
}								t_vm;

/*
**	t_count is needed to parse champion file
*/

typedef struct					s_count
{
	int							c;
	int							m;
	int							j;
	int							k;
	int							l;
}								t_count;

/*
**  t_car  Struct for carriges(processes)
**	car->pos = has every step of carrriage
**	car->pc jumps from command to command ()
*/

typedef struct					s_car
{
	int							id;
	int							pos;
	int							pc;
	int							reg[REG_NUMBER];
	int							carry;
	t_bool						is_type_code;
	int							arg[3];
	unsigned int				arg_type[3];
	int							parent_car;
	unsigned int				last_live_cycle;
	unsigned int				op_code;
	unsigned int				wait;
	unsigned int				dir_size_status;
	struct s_car				*hd_cars;
	struct s_car				*next;
}								t_car;

typedef struct					s_op
{
	char						*name;
	unsigned int				code;
	unsigned int				args_amount;
	t_bool						is_type_code;
	unsigned int				args_types[3];
	t_bool						modify_carry;
	unsigned int				dir_size_status;
	unsigned int				cycles_wait;
	void						(*func)(t_car *, uint8_t *);
}								t_op;

typedef struct					s_op_ld
{
	int		val;
	int		num_reg;
	int		addr;
}								t_op_ld;

typedef struct					s_op_and
{
	int		arg1;
	int		arg2;
	int		arg3;
	int		val;
}								t_op_and;

/*
**	init car
*/

t_plr							*add_one_plr(char **argv, t_plr *plr, int i, \
																		int j);
void							check_flags(int argc, char **argv, t_vm *vm);
int								chek_num(int *num, int minnum, int plrs);
void							check_same_numb(int *num, t_plr *plr, int plrs);
void							check_n_flags(int argc, char **argv, \
																	t_plr *plr);
void							checkdotcor_and_chech_n(int ac, char **av, \
															int *n, t_plr *pr);
int								checkdotcor(char *argv);
void							check_max_size_and_magicnum(t_plr *plr, \
													uint8_t *magicnum, int fd);
void							create_list_plr(t_plr *head, int val, int fd);
void							copy_num_in_plrslist(int *num, t_plr *plr, \
																	int plrs);
int								comparison_of_two_numbers(int a, int b);
void							error_champ_max_size();
void							error_file();
void							error_magic_numb();
void							error_one_dump();
void							error_pos_number();
t_plr							*ft_parse(int argc, char **argv, int i, int id);
void							get_sizecode(t_plr *plr, uint8_t *sizecode);
void							gat_list_plrs(char **argv, int id, t_plr *plr, \
																		int i);
int								get_error_for_n(int i, int argc, char **argv);
t_car							*make_car(t_plr *plr, t_vm *vm);
int								number_after_n(int i, char **argv);
t_plr							*sort_list_plr(t_plr *plr);
void							print_error(int num_error);
int								plr_count(t_plr *head);
void							put_number_in_arr(int *num, t_plr *plr, \
																	int plrs);
int								read_from_file(t_plr *player, char *str, \
																	int nbr);
void							read_file(int fd, t_plr *plr, int i);
t_plr							*revlist(t_plr *plr);
int								right_n_flag(int argc, char **argv);
void							init_car(t_plr *plr, t_car **head, int pos);
int								is_num(char *str);

/*
**	init arena
*/

void							fill_arena(t_plr *plr, uint8_t *arena);
void							ft_copy_code(uint8_t *dst, uint8_t *src, \
																int codesize);

/*
**	init t_vm, t_op, t_plr
*/

void							init_vm(t_vm *vm);
void							init_plr(t_vm *vm, t_plr *plr);

/*
**	parse
*/

void							check_flags(int argc, char **argv, t_vm *vm);
void							check_n_flags(int argc, char **argv, \
																	t_plr *plr);
t_plr							*ft_parse(int argc, char **argv, int i, int id);

/*
**	utils
*/

int								update_pos(int pos);
uint8_t							get_byte(uint8_t *arena, t_car *car);
void							dump(uint8_t *arena);
void							introduce_plrs(t_plr *plr);
int								arena_loop(uint8_t *arena, uint32_t coord);
int								is_num(char *str);
int								checkdotcor(char *argv);
void							print_error(int num_error);
t_bool							valid_op(t_car *car);
int								if_aff(int c);
void							put_value_in_arena(uint8_t *arena, \
							int32_t new_adr, int32_t val_in_reg1, int32_t size);
signed char						get_byte_signed_char(uint8_t *arena, \
																	t_car *car);

/*
**	зачистка всего
*/

void							ft_free_plr(t_plr *plr);
void							del_car(t_car *head_car);
void							free_all(t_plr *plr, t_vm *vm, t_car *head_car);

/*
**	game
*/

void							game(t_car **head_car, uint8_t *arena, \
																t_vm *vm);
void							cycle(t_car **head_car, uint8_t *arena, \
																t_vm *vm);
void							check(t_vm *vm, t_car **head_car);
void							bury_car(t_vm *vm, t_car **head_car);
void							check_winner(t_vm *vm);
int								get_args_type(t_car *car, uint8_t *arena, \
																t_op *op);
void							write_arg_type(int arg_type, t_car *car, \
																int ind);
void							exec(t_car *car, uint8_t *arena, t_op *op, \
																t_vm *vm);
int								get_arg(t_car *car, int arg_number, \
																uint8_t *arena);
int								weight(int a, int c);
int								move(t_car *car);
int								read_int(const uint8_t *arena, int pos, \
																int size);
void							make_new_car(t_car *car, int new_adr);
void							choose_1(t_car *car, uint8_t *arena);
void							choose_2(t_car *car, uint8_t *arena);
void							check_carry_status(int val, t_car *car);
void							walk(t_car *car, int steps);

void							op_live(t_car *car, uint8_t *arena, t_vm *vm);
void							op_ld(t_car *car, uint8_t *arena);
void							op_st(t_car *car, uint8_t *arena);
void							op_add(t_car *car, uint8_t *arena);
void							op_sub(t_car *car, uint8_t *arena);
void							op_and(t_car *car, uint8_t *arena);
void							op_and_1(t_op_and *and, t_car *car, \
																uint8_t *arena);
void							op_or(t_car *car, uint8_t *arena);
void							op_xor(t_car *car, uint8_t *arena);
void							op_zjmp(t_car *car, uint8_t *arena);
void							op_ldi(t_car *car, uint8_t *arena);
void							op_sti(t_car *car, uint8_t *arena);
void							op_fork(t_car *car, uint8_t *arena);
void							op_lld(t_car *car, uint8_t *arena);
void							op_lldi(t_car *car, uint8_t *arena);
void							op_lfork(t_car *car, uint8_t *arena);
void							op_aff(t_car *car, uint8_t *arena);

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
		.func = NULL
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
		.func = NULL
	}
};

#endif
