/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_writing_by_bytes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:34:02 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/05 14:06:30 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	writing_four_bytes(t_crw *champ, unsigned int to_write)
{
	unsigned char	buff;
	int				shift;

	shift = 24;
	while (shift >= 0)
	{
		buff = (unsigned char)((to_write >> shift));
		champ->exec_code[champ->ind_wr] = buff;
		shift -= 8;
		champ->ind_wr++;
	}
}

void	writing_two_bytes(t_crw *champ, unsigned int to_write)
{
	unsigned char	buff;
	int				shift;

	shift = 8;
	while (shift >= 0)
	{
		buff = (unsigned char)((to_write >> shift));
		champ->exec_code[champ->ind_wr] = buff;
		shift -= 8;
		champ->ind_wr++;
	}
}

void	writing_one_byte(t_crw *champ, unsigned int to_write)
{
	champ->exec_code[champ->ind_wr++] = (unsigned char)(to_write);
}
