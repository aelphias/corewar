/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:58 by aelphias          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/19 14:14:16 by gjigglyp         ###   ########.fr       */
=======
/*   Updated: 2020/12/19 15:09:28 by aelphias         ###   ########.fr       */
>>>>>>> b833810c6eb9cec44ced071bd7d19a6fb9ba32cc
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "../includes/op.h"
# include "errors.h"

typedef struct s_flg
{
	int	n; 
	int dump;
}				t_flg;

void	print_error(int num_error);
void	ft_parse(int argc, char **argv, t_flg *flag);
void	check_flags(int argc, char **argv, t_flg *flag);


#endif