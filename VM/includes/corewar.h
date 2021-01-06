/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/06 19:49:15 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "../includes/op.h"
# include "errors.h"

typedef enum { false, true } bool;

/* 
*	uint8_t  1 байт - 8 бит, тип фиксированного размера, unsigned, от 0 до 255
*/

typedef struct		s_vm
{
	//uint8_t			arena[MEM_SIZE]; ?
	int				num_plr; //number of players
	int				num_car;
	long int		cycles;
	long int		cycles_to_die;
	long int		cycles_aff_check;
	int				n; // флаг n
	int				dump;			// флаг dump
}					t_vm;

typedef struct			s_car
{
	int				carry;
	uint8_t			position; // место где мы ее ставим при начале игры
	uint8_t			reg[REG_NUMBER];
	int				id;
	uint8_t			arg[3];
	int				parent_car;
	int				live;
	int				op_code;
	int				wait;
	struct s_car	*next;
}					t_car;

typedef struct		s_op
{
	char			*name;							//	0
	uint8_t			args_amount;					//	1
	uint8_t			args_types[3];					//	2
	uint8_t			code;							//	3
	uint32_t		cycle_wait;						//	4
	char			*comment;						//	5
	bool			modify_carry;					//	6
	uint8_t			t_dir_size;						//	7
	bool			args_types_code;				//	8  check it is true
	void			(*func)(t_car *, uint8_t *);	//	9 //? может передовать t_vm а не карту?
}					t_op;

typedef struct		s_plr
{
	int				id;
	uint8_t			*name;
	uint8_t			*cmnt;
	uint8_t			position; // место где мы его ставим при начале игры
	int				codesize;
	uint8_t			*code;
	struct s_plr	*next;
}					t_plr;



/*
*	parse
*/

t_plr	*ft_parse(int argc, char **argv);
void	check_flags(int argc, char **argv, t_vm *vm);
int	read_from_file(t_plr *player, char *str, int nbr);
void	print_error(int num_error);

/*
*	init car
*/

void	init_car(t_plr *plr, t_car **head, int pos);
t_car	*make_car(t_plr *plr, t_vm *vm);
int	plr_count(t_plr *head);

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
void	init_op(t_vm op[17]);


/*
*	utils
*/

void	dump(uint8_t *arena);
void	introduce_plrs(t_plr *plr);
int	get_map(uint8_t *arena, int coord);

/*
*	зачистка всего
*/
void	ft_free_vm(t_vm *vm);
void	ft_free_plr(t_plr *plr);

/*
*	game
*/
void	game(t_plr *plr, t_car **car, uint8_t *arena, t_vm *vm);

/*
*	operations
*/
void	op_fork(t_car *head, t_car * n_car, uint8_t *arena);
void	op_add(t_car *car, uint8_t *arena);
void	operations(t_car *car, uint8_t *arena, void (**func)(t_car *, uint8_t *));



/*
*	testing
*/
void	test(t_vm *vm, t_plr *plr);
void	print_list(t_plr *plr);
void	print_list_car(t_car *car);

/*
*	alfa version op_tab
*/




#endif
