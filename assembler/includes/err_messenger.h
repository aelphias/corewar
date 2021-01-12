/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_messenger.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:46:34 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/05 14:14:58 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MESSENGER_H
# define ERR_MESSENGER_H

# include "asm.h"

# define ARG_III "Argument(-s) is/are not valid"
# define ER_F_RD "File could not be read"
# define ER_IN_F "Invalid file"
# define ERR_F_C "ERROR: file not created"
# define ER_N_AR "Negative argument type (for operation)"
# define ERR_INV "Invalid registry name for operation"
# define OP_SIZE "Ircorrect size for operation"
# define ER_I_AR "Error: invalid arg"
# define ER_ININ "Error: ircorrect input"
# define LAB_N_F "Label is not found"
# define LAB_ARG "Incompatible combination ARG-LABEL"
# define ARG_INV "Invalid type of an arguement"
# define CHA_SET "Name of champion is not set!"
# define CHA_COM "Champion comment is not set!"
# define CHA_INS "Champion has not any instructions"
# define ERR_FNL "File is not found or no new line at the end"
# define MAIN_CO "No main comment"
# define MORE_CO "The number of comments is 2 or more"
# define MEM_ALL "Memory did not allocated"
# define LONG_NA "Name is too long!!!"
# define NO_NAME "The file does not contatin name"
# define NO_LABE "The file does not contatin label"
# define NO_N_CO "The file does not contain comment and/or name"
# define LONG_CO "Comment is too long!!!"
# define MARG_NV "MAX_ARGS value is not valid"
# define ER_ARGV "One of the arguements is not valid"
# define ERR_UNF "Unsupportable type of file"
# define ERR_USE "Usage: ./asm [name_of_file.s/name_of_file.cor]"

#endif
