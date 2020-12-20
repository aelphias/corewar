/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/20 20:05:57 by aelphias         ###   ########.fr       */
=======
/*   Updated: 2020/12/19 19:20:27 by gjigglyp         ###   ########.fr       */
>>>>>>> 9c1ee0882eb7d560c543d5fda39774a9f00546f0
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "../includes/op.h"
# include "errors.h"

typedef struct	s_flg
{
	int			n;
	int			dump;
}				t_flg;

typedef struct	s_plr
{
	char 		*name;
	int			plr_count;
}				t_plr;

void	print_error(int num_error);
void	ft_parse(int argc, char **argv, t_flg *flag, t_plr *plr);
void	check_flags(int argc, char **argv, t_flg *flg, t_plr *plr);

/*
*	testing
*/
void	test(t_flg *flg, t_plr *plr);

#endif
