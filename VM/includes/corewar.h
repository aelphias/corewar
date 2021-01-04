/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/04 21:07:34 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "../includes/op.h"
# include "errors.h"

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)

typedef struct	s_vm
{
	//int			arena[MEM_SIZE];
	int			num_plr; //number of players
	long int	cycles;
	long int	cycles_to_die;
	long int	cycles_aff_check;
	int			n;            // флаг n
	int			dump;			// флаг dump
}				t_vm;

typedef struct s_plr
{
	int					id;
	unsigned char		*name;
	unsigned char		*cmnt;
	unsigned int		position; // место где мы его ставим при начале игры
	int					codesize;
	unsigned int		*code;
	struct s_plr		*next;
}				t_plr;

typedef struct			s_car
{
	int					carry;
	unsigned int		position; // место где мы ее ставим при начале игры
	unsigned int		reg[REG_NUMBER];
	int					id;
	unsigned int		arg[3];
	struct s_car		*next;
	int					parent_car;
	int					live;
	int					op_id;
}						t_car;

/* typedef struct s_op
{
	int op_id;
}				t_op;
 */
/*
*	parse
*/
void	print_list(t_plr *plr);

void	print_error(int num_error);
t_plr	*ft_parse(int argc, char **argv, t_vm *vm);
void check_flags(int argc, char **argv, t_vm *vm);
int		read_from_file(t_plr *player, char *str, int nbr);

/*
*	init car
*/
t_car	*make_car(t_plr *plr, t_vm *vm);
int		plr_count(t_plr *head);
void	print_list_car(t_car *car);

/*
*	init arena 
*/

void	fill_arena(t_plr *plr, t_vm *vm, unsigned char *arena);
//void	ft_copy_code(unsigned char *dst, unsigned int *src);
void	ft_copy_code(unsigned char *dst, unsigned int *src, int codesize);


/*
*	инициализация всего
*/
void	init_vm(t_vm *vm);
void	init_car(t_plr *plr, t_car **head, int pos, t_vm *vm);

/*
*	utils
*/
void	dump(unsigned char *arena);
void	introduce_plrs(t_plr *plr);

/*
*	зачистка всего
*/
void ft_free_vm(t_vm *vm);
void ft_free_plr(t_plr *plr);

/*
*	game
*/
void	game(t_plr *plr, t_car **car, unsigned char *arena, t_vm *vm);

/*
*	operations
*/
void	op_fork(t_car *head, t_car * n_car, unsigned int *arena);
void	op_add(t_car *car, unsigned char *arena);
void	operations(t_car *car, unsigned char *arena, void (**func)(t_car *, unsigned char *));



/*
*	testing
*/
void	test(t_vm *vm, t_plr *plr);
void	print_list(t_plr *plr);

/*
*	alfa version op_tab
*/

/* 
typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	int		args_types_code;   // ??
	uint8_t		args_types[3];  //  ???
	int		modify_carry;
	uint8_t		t_dir_size;
	uint32_t	cycles;
	void		(*func)(t_vm *, t_cursor *);

}				t_op;


static t_op		g_op[17] = {
	{
		.name = 0,
		.code = 0x01,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_live
	},
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_st
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 20,
		.func = &op_zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 800,
		.func = &op_fork
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = true,
		.t_dir_size = 2,
		.cycles = 50,
		.func = &op_lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 1000,
		.func = &op_lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = true,
		.args_types = {T_REG, 0, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 2,
		.func = &op_aff
	}
}; */
#endif
