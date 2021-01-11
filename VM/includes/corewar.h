/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/11 16:12:32 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "../includes/op.h"
# include "errors.h"

typedef enum { false, true } bool;

# define MINUS_ONE(X)		((X) - 1)


/* 
*	uint8_t  1 байт - 8 бит, тип фиксированного размера, unsigned, от 0 до 255
*/

typedef struct		s_vm
{
	//uint8_t			arena[MEM_SIZE];  может запихнуть сюда
	unsigned int	plr_count; //number of players
	unsigned int	lived; //number of players
	int				car_count;
	long int		check_count;
	long int		cycles;
	long int		cycles_to_die;
	long int		cycles_aff_check;
	int				n; // флаг n
	int				dump;			// флаг dump
	char			*winner;
//	t_car			**head_car;  может добавить и носить с собой? и тогда передаем просто vm 
}					t_vm;

typedef struct		s_car
{
	bool			carry;
	unsigned int	position; // место где мы ее ставим при начале игры
	uint8_t			reg[REG_NUMBER];
	int				id;
	uint8_t			arg[3];
	uint8_t			arg_type[3];
	int				parent_car;
	unsigned int	last_live; // цикл в котором в прошлый раз была выполнена op_live
	unsigned int	op_code;
	unsigned int	wait;
	unsigned int	pc; //сколько байт перешагнуть чтобы оказаться на след интсрукции
	unsigned int	dir_size_status;
	bool			demolish;
	struct s_car	*next;
}					t_car;

typedef struct		s_plr
{
	int				id;
	int				n_id;
	uint8_t			*name;
	uint8_t			*cmnt;
	unsigned int	position; // место где мы его ставим при начале игры
	unsigned int	codesize;
	uint8_t			*code;
	struct s_plr	*next;
}					t_plr;

/* typedef struct		s_op
{
	char			*name;							//	0
	unsigned int	args_amount;					//	1
	char			*args_types[3];					//	2
	unsigned int	code;							//	3
	unsigned int	cycle_wait;						//	4
	char			*comment;						//	5
	bool			modify_carry;					//	6
	unsigned int	dir_size_status;						//	7
	bool			args_types_code;				//	8  check it is true
	void			(*func)(t_car *, uint8_t *);	//	9 //? uint8_t* (arena) может передовать t_vm а не карту?
}					t_op;
 */



/*
*	parse
*/

t_plr	*ft_parse(int argc, char **argv);
void	check_flags(int argc, char **argv, t_vm *vm);
int		read_from_file(t_plr *player, char *str, int nbr);
void	print_error(int num_error);
void 	check_n_flags(int argc, char **argv, t_plr *plr);

/*
*	init car
*/

void	init_car(t_plr *plr, t_car **head, int pos);
t_car	*make_car(t_plr *plr, t_vm *vm);
int		plr_count(t_plr *head);

/*
*	init arena 
*/

void	fill_arena(t_plr *plr, t_vm *vm, uint8_t *arena);
//void	ft_copy_code(uint8_t *dst, uint8_t *src);
void	ft_copy_code(uint8_t *dst, uint8_t *src, int codesize);

/*
*	инициализация t_vm, t_op
*/

void	init_vm(t_vm *vm);
//void	init_op(t_op op[17]);

/*
*	utils
*/

unsigned int	update_pos(unsigned int pos);
uint8_t	get_byte(uint8_t *arena, unsigned int position);
void	dump(uint8_t *arena);
void	introduce_plrs(t_plr *plr);
int	arena_loop(uint8_t *arena, uint32_t coord);

/*
*	зачистка всего
*/
void	ft_free_vm(t_vm *vm);
void	ft_free_plr(t_plr *plr);

/*
*	game
*/
void	game(t_car **car, uint8_t *arena, t_vm *vm);
void	check(t_vm *vm, t_car **head_car);
void	bury_car(t_vm *vm, t_car **head_car);
void	get_args(t_car *car, unsigned char *arena);
void	check_winner(t_vm *vm);
/*
*	operations
*/
//void	operations(t_car *car, uint8_t *arena, void (**func)(t_car *, uint8_t *));
//void	no();
void	op_live(t_car *car, uint8_t *arena);
void	op_ld(t_car *car, uint8_t *arena);
void	op_st(t_car *car, uint8_t *arena);
void	op_add(t_car *car, uint8_t *arena);
void	op_sub(t_car *car, uint8_t *arena);
void	op_and(t_car *car, uint8_t *arena);
void	op_or(t_car *car, uint8_t *arena);
void	op_xor(t_car *car, uint8_t *arena);
void	op_zjmp(t_car *car, uint8_t *arena);
void	op_ldi(t_car *car, uint8_t *arena);
void	op_sti(t_car *car, uint8_t *arena);
void	op_fork(t_car *car, uint8_t *arena);
void	op_lld(t_car *car, uint8_t *arena);
void	op_lldi(t_car *car, uint8_t *arena);
void	op_lfork(t_car *car, uint8_t *arena);
void	op_aff(t_car *car, uint8_t *arena);

/*
*	testing
*/
void	test(t_vm *vm, t_plr *plr);
void	print_list(t_plr *plr);
void	print_list_car(t_car *car);
//void	print_op(t_op op[17]);


/*
*	alfa version op_tab
*/

typedef struct		s_op
{
	char			*name;
	unsigned int	code;
	unsigned int	args_amount;
	bool			args_types_code;   // ??
	unsigned int	args_types[3];  //  ???
	bool			modify_carry;
	unsigned int	dir_size_status;
	unsigned int	cycles_wait;
	void			(*func)(t_car *, uint8_t *);;

}					t_op;

static t_op		g_op[16] = {
	{
		.name = "live",
		.code = 1,
		.args_amount = 1,
		.args_types_code = false,
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
		.args_types_code = true,
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
		.args_types_code = true,
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
		.args_types_code = true,
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
		.args_types_code = true,
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
		.args_types_code = true,
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
		.args_types_code = true,
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
		.args_types_code = true,
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
		.args_types_code = false,
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
		.args_types_code = true,
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
		.args_types_code = true,
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
		.args_types_code = false,
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
		.args_types_code = true,
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
		.args_types_code = true,
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
		.args_types_code = false,
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
		.args_types_code = true,
		.args_types = {T_REG, 0, 0},
		.modify_carry = false,
		.dir_size_status = 4,
		.cycles_wait = 2,
		.func = &op_aff
	}
};

#endif
