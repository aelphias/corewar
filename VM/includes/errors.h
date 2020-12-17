/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:07:58 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/17 20:06:31 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "corewar.h"

# define ERR_USE "Usage: ./corewar [-d N -s N -v N | -b --stealth | -n --stealth] [-a] <champion1.cor> <...>\
    -a        : Prints output from "aff" (Default is to hide it)\
#### TEXT OUTPUT MODE ##########################################################\
    -d N      : Dumps memory after N cycles then exits\
    -s N      : Runs N cycles, dumps memory, pauses, then repeats\
    -v N      : Verbosity levels, can be added together to enable several\
                - 0 : Show only essentials\
                - 1 : Show lives\
                - 2 : Show cycles\
                - 4 : Show operations (Params are NOT litteral ...)\
                - 8 : Show deaths\
                - 16 : Show PC movements (Except for jumps)\
#### BINARY OUTPUT MODE ########################################################\
    -b        : Binary output mode for corewar.42.fr\
    --stealth : Hides the real contents of the memory\
#### NCURSES OUTPUT MODE #######################################################\
    -n        : Ncurses output mode\
    --stealth : Hides the real contents of the memory\
################################################################################"
# define ARG_III "Argument(-s) is/are not valid"
# define ER_F_RD "File could not be read"
# define ERR_F_C "ERROR: file not created"
# define ER_N_AR "Negative argument type (for operation)"
# define ERR_INV "Invalid registry name for operation"
# define OP_SIZE "Ircorrect size for operation"
# define LAB_N_F "Label is not found"
# define LAB_ARG "Incompatible combination ARG-LABEL"
# define ARG_INV "Invalid type of an arguement"
# define CHA_SET "Name of champion is not set!"
# define CHA_COM "Champion comment is not set!"
# define CHA_INS "Champion has not any instructions"
# define LONG_NA "Name is too long!!!"
# define LONG_CO "Comment is too long!!!"
# define MARG_NV "MAX_ARGS value is not valid"
# define ER_ARGV "One of the arguements is not valid"
# define ERR_UNF "Unsupportable type of file"

#endif
