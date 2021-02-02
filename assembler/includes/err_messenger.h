/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_messenger.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:46:34 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/28 19:16:45 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MESSENGER_H
# define ERR_MESSENGER_H

# include "asm.h"

# define ARG_III "Argument(-s) is/are not valid or their number is wrong"
# define ER_F_RD "File could not be read"
# define ER_IN_F "Invalid file"
# define ERR_F_C "The file not created"
# define ER_IN_C "Invalid command"
# define NO_ARGS "NO ARGUMENT WERE FOUND"
# define NO_VALA "NO VALID ARGUMENT IS FOUND"
# define LEX_ERR "Lexical error(-s) is(are) found"
# define COMXTRA "Extra comma has been found"
# define COM_FEW "Too few commas has been found"
# define COM_BAD "Error(-s) in commas is(are) found"
# define ER_N_AR "Negative argument type (for operation)"
# define ERR_INV "Invalid registry name for operation"
# define OP_SIZE "Ircorrect size for operation"
# define ER_I_AR "Invalid arg"
# define LBL_DUP "Label duplicate is found"
# define ER_I_ST "Invalid string"
# define ERR_EST "empty name and/or comment"
# define NO_COMM "File does not contain any commands (i.e. no execution code)"
# define ER_ININ "Error: ircorrect input"
# define ERR_COM "Error: the file does not contain any commas"
# define ERR_COE "Error: extra comma was found"
# define LAB_N_F "Label is not found"
# define LAB_ARG "Incompatible combination ARG-LABEL"
# define LAB_EXI "There is a label that does not exist"
# define ARG_INV "The file contains an invalid type of an arguement"
# define CHA_SET "Name and/or comment of champion may contain invalid data!"
# define CHA_INS "Champion has not any instructions"
# define CHA_NAM "Champion has got the irrcorect name"
# define CHA_COM "Champion has got the irrcorect name"
# define ERR_FNL "File is not found or no new line at the end"
# define MAIN_CO "No main comment"
# define MORE_CO "The number of comments is 2 or more"
# define MORE_CH "The number of champs name is 2 or more"
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
