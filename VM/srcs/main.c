/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/19 15:21:47 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** strerror
** perror
*/



int	main(int argc, char **argv)
{
	t_flg *flag;

	flag = (void*)malloc(sizeof(t_flg)); // add check
	argc == 1 ? print_error(ERR_USE) : 0;
	ft_parse(argc - 1, argv, flag);
	return (0);
}
