/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/25 15:01:50 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "../includes/op.h"
# include "errors.h"

typedef struct	s_vm
{
	int			arena[MEM_SIZE];
	int			nop; //number of players
	ssize_t 	cycles;
	ssize_t 	c2d; //cycles to die
	ssize_t 	cac; //cycles after check
	int			print_mode;
}				t_vm;

typedef struct s_plr
{
	int			id;
	char		*name;
	char		*cmnt;
	char		*code;
	// int			soc;
	// int			cur_ln;
	// int			prev_ln;
	// int			ll;
	// int			plr_count;
	struct s_plr		*next;
}				t_plr;

typedef struct s_flg
{
	int	n; 
	int dump;
}				t_flg;

/*
*	parse
*/

void	print_error(int num_error);
void	ft_parse(int argc, char **argv, t_flg *flag, t_plr **plr);
void	check_flags(int argc, char **argv, t_flg *flg, t_plr **plr);
void	try_to_read(char *fname, t_plr **plr);

/*
*	utils
*/
void	create_list_plr(t_plr *head, int val);
void	print_list(t_plr *plr);
int	is_num(char *str);

/*
*	test
*/
void	test(t_flg *flg, t_plr **plr);

#endif