/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:11:43 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/17 21:44:19 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


/*
** strerror
** perror
*/

<<<<<<< HEAD
/* void	ft_parse(int argc, char **argv)
{
	MAX_PLAYERS > argc ? perror() : 0;
} */

int	main()
=======
void	ft_parse(int argc, char **argv)
{
	MAX_PLAYERS > argc ? perror() : 0;
}

int	main(int argc, char **argv)
>>>>>>> c9fe04b58f4cddf45efdad4ab822f6d847935244
{
	/*
	*checking filename and magic header
	*/
<<<<<<< HEAD
	/* argc == 1 ? ft_printf("%s\n", ERR_USE) : 0; */
	ft_printf("%s\n", ERR_USE);
	//ft_parse(argc, argv);
=======
	argc == 1 ? ft_printf("%s\n", ERR_USE) : 0;
	ft_parse(argc, argv);
>>>>>>> c9fe04b58f4cddf45efdad4ab822f6d847935244
	return (0);
}
