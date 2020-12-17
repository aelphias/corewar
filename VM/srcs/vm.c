/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/17 19:01:52 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


/*
** strerror
** perror
*/

void	ft_parse(int argc, char **argv)
{
	MAX_PLAYERS > argc ? perror() : 0;
}

int	main(int argc, char **argv)
{
	/*
	*checking filename and magic header
	*/
	argc == 1 ? ft_printf("%s\n", ERR_USE) : 0;
	ft_parse(argc, argv);
	return (0);
}
