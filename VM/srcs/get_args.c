/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:19:27 by kcharlet          #+#    #+#             */
/*   Updated: 2021/01/09 22:14:48 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/* void	get_dir(t_car *car, unsigned char *arena, t_op *op)
{
	
}
 */

/* 
* 1  0000 0001
# 2  0000 0010
# 3  0000 0011
*/

/* 
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3 */

/* 
	int			bit_mask;
	if (stand == 1)
		bit_mask = 192;
	else
		(stand == 2) ? (bit_mask = 48)
			: (bit_mask = 12);
	if ((size & bit_mask) == (bit_mask - (bit_mask / 3)))
		return (3);
	if ((size & bit_mask) == bit_mask)
		return (2);
	if ((size & bit_mask) == (bit_mask / 3))
		return (1);
	return (0);
	 */


/* void	get_args_types(uint8_t arg_type, t_car *car)
{
	int			bit_mask;
	bit_mask = 192;
	if (arg_type & bit_mask)
		car->arg_type[0] = REG_CODE;
	else if (arg_type & bit_mask)
		car->arg_type[0] = REG_CODE;
	
	car->arg_type[1];
	car->arg_type[2];
}


void	get_args(t_car *car, unsigned char *arena, t_op *op)
{
	if (op[car->op_code].args_types_code)
	{
		car->position++;
		get_args_types(get_byte(arena, car->position));
		printf("---->get_args is here, darling!\n");
	}
	 else
		get_dir(arena, car); 
}

 */