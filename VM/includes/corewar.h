/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/28 18:36:43 by kcharlet         ###   ########.fr       */
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
	int			arena[MEM_SIZE];
	int			nop; //number of players
	ssize_t 	cycles;
	ssize_t 	cycles_to_die;
	ssize_t 	cac; //cycles after check
	int			print_mode;
	int			n;
	int			dump;
}				t_vm;

typedef struct s_plr
{
	int					id;
	unsigned char		*name;
	unsigned char		*cmnt;
	unsigned int		*code;
	unsigned int		position; // место где мы его ставим при начале игры
	int					codesize;
	struct s_plr		*next;
}				t_plr;

typedef struct s_car
{

}				t_car;

typedef struct s_op
{
	/* data */
}				t_op;




void	print_error(int num_error);
t_plr	*ft_parse(int argc, char **argv, t_vm *vm);
void	check_flags(int argc, char **argv, t_vm *vm, t_plr *plr);
int		read_from_file(t_plr *player, char *str, int nbr);

int		plr_count(t_plr *head);
t_vm	*make_car(t_plr *plr, t_vm *vm);
/*
*	testing
*/
void	test(t_vm *vm, t_plr *plr);


/*
*	инициализация всего
*/
void init_vm(t_vm *vm);

/*
*	зачистка всего
*/
void ft_free_vm(t_vm *vm);
void ft_free_plr(t_plr *plr);



#endif