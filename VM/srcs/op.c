/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 00:11:29 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/08 21:23:38 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	no()
{
	
}

void init_op(t_op op[17])
{	
	op[0] = (t_op){0, 0, {0}, 0, 0, 0, 0, 0, no};
	op[1] = (t_op){"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, op_live};
	op[2] = (t_op){"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, op_ld}; // загрузка значения в регистр. 
	op[3] = (t_op){"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, op_st}; // записывает значение из регистра
	op[4] = (t_op){"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, op_add}; // складывает значения в регистрах
	op[5] = (t_op){"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, op_sub};
	op[6] = (t_op){"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, op_and};
	op[7] = (t_op){"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, op_or};
	op[8] = (t_op){"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, op_xor};
	op[9] = (t_op){"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, op_zjmp}; //может перебросить нас на N-ое количество байтов вперед или назад.
	op[10] = (t_op){"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, op_ldi};
	op[11] = (t_op){"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, op_sti};
	op[12] = (t_op){"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, op_fork};
	op[13] = (t_op){"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, op_lld};
	op[14] = (t_op){"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, op_lldi};
	op[15] = (t_op){"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, op_lfork};
	op[16] = (t_op){"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, op_aff};
}

/*

 t_op    op_tab[17] =                   // 17 у игоря потомучто здесь 17! послдний 17-й збит нулями
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	/*На операцию live возложены две функции:
    Она засчитывает, что каретка, которая выполняет операцию live, жива.
    Если указанный в качестве аргумента операции live номер совпадает с номером игрока, то она засчитывает,
	что это игрок жив. Например, если значение аргумента равно -2, значит игрок с номером 2 жив.

   //  0   1				2		  3   4     5   6  7 
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0}, // загрузка значения в регистр. 
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0}, // записывает значение из регистра
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0}, // складывает значения в регистрах
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1}, //может перебросить нас на N-ое количество байтов вперед или назад.
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
}; 
*/
