/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/31 18:40:40 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "../includes/op.h"
# include "errors.h"

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)

/*
* t_vm:
* nop - number of players
* c2d - cycles to die
* cac - cycles after check
*/

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
	unsigned int		reg[16];
	int					id;
	unsigned int		arg[3];
	struct s_car		*next;
	int					parent_car;
	int					live;
	unsigned int		*code;
}						t_car;

typedef struct s_op
{
	/* data */
}				t_op;

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
void	ft_copy_code(unsigned char *dst, unsigned int *src);


/*
*	testing
*/
void	test(t_vm *vm, t_plr *plr);


/*
*	инициализация всего
*/
void	init_vm(t_vm *vm);
void	init_car(t_plr *plr, t_car **head, int pos, t_vm *vm);

/*
*	utils
*/
void	dump(unsigned char *arena);
void	introduce_plrs(t_plr *plr, t_vm *vm);

/*
*	зачистка всего
*/
void ft_free_vm(t_vm *vm);
void ft_free_plr(t_plr *plr);

/*
*	game
*/
void	game(t_plr *plr, t_car *car, unsigned int *arena, t_vm *vm, t_op *op);
void	forkk(t_car *head, unsigned int *arena);


#endif
