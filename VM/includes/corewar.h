/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/22 18:47:53 by gjigglyp         ###   ########.fr       */
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
	int			soc;
	int			cur_ln;
	int			prev_ln;
	int			ll;
	struct s_plr		*next;
}				t_plr;

typedef struct s_flg
{
	int	n; 
	int dump;
}				t_flg;

void	print_error(int num_error);
void	ft_parse(int argc, char **argv, t_flg *flag);
void	check_flags(int argc, char **argv, t_flg *flag);


#endif