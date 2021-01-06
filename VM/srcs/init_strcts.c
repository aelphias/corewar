/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:29:10 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/06 19:52:19 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void init_vm(t_vm *vm)
{
	vm->dump = -1;
}

/* void init_op(t_vm *op)
{	
	op[1] = (t_vm){"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, op_live};
	op[2] = (t_vm){"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, op_ld}; // загрузка значения в регистр. 
	op[3] = (t_vm){"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, op_st}; // записывает значение из регистра
	op[4] = (t_vm){"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, op_add}; // складывает значения в регистрах
	op[5] = (t_vm){"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, op_sub};
	op[6] = (t_vm){"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, op_and};
	op[7] = (t_vm){"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, op_or};
	op[8] = (t_vm){"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, op_xor};
	op[9] = (t_vm){"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, op_zjmp}; //может перебросить нас на N-ое количество байтов вперед или назад.
	op[10] = (t_vm){"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, op_ldi};
	op[11] = (t_vm){"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, op_sti};
	op[12] = (t_vm){"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, op_fork};
	op[13] = (t_vm){"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, op_lld};
	op[14] = (t_vm){"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, op_lldi};
	op[15] = (t_vm){"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, op_lfork};
	op[16] = (t_vm){"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, op_aff};
} */

