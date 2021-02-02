# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:51:23 by aelphias          #+#    #+#              #
#    Updated: 2021/02/02 20:36:57 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re pwdfclean directory

COREWAR 	= corewar
ASM		 	= asm
VM_PATH 	= ./VM/
ASM_PATH 	= ./assembler/
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

LIB_DIR		=	libft/
LIB_A		=	$(LIB_DIR)libft.a
LIB_HEAD	=	$(LIB_DIR)libft.h
LIB_OBJ		= 	libft/objects/
INC_ALL		=	includes/op.h

####################DIRS_VM########################################################

INC_DIR_VM		=	./VM/includes/
OBJ_DIR_VM		=	./VM/obj/
SRC_L_D_VM		=	./VM/srcs/
SRC_LIB			=	./libft/

HEAD_VM		=	$(INC_DIR_VM)corewar.h
INC_VM		=	-I$(LIB_DIR) -I$(INC_DIR_VM)

####################DIRS_ASM########################################################

INC_DIR_ASM		=	./assembler/includes/
OBJ_DIR_ASM		=	./assembler/obj/
SRC_L_D_ASM		=	./assembler/srcs/

HEAD_ASM		=	$(INC_DIR_ASM)asm.h
INC_ASM			=	-I$(LIB_DIR) -I$(INC_DIR_ASM)

#####################VM_SOURCES##################################################

VM_SRC_LIST	= print_error.c \
			  parsing.c \
			  parse_flags.c \
			  plr_count.c \
			  make_car.c \
			  fill_arena.c \
			  dump.c \
			  game.c \
			  init_strcts.c \
			  introduce_plrs.c \
			  main.c \
			  op_add.c \
			  get_args_type.c\
			  update_pos.c\
			  op_live.c \
			  op_ld.c \
			  op_st.c \
			  op_sub.c\
			  op_and.c\
			  op_or.c\
			  op_xor.c\
			  op_ldi.c\
			  op_zjmp.c\
			  op_sti.c\
			  op_fork.c\
			  op_lld.c\
			  op_lldi.c\
			  op_lfork.c\
			  op_aff.c\
			  bury_car.c\
			  parse_n_flag.c \
			  parse_n_flag_cont.c \
			  func_for_parsing.c \
			  get_arg.c\
			  move.c \
			  put_value_in_arena.c\
			  choose.c\
			  check.c\
			  utils_for_op.c \
			  print_error2.c

SRC_VM		= 	$(VM_SRC_DIR), $(VM_SRC_LIST))
OBJ_VM		=	$(VM_SRC_LIST:%.c=%.o)
SRCS_VM		=	$(addprefix $(SRC_L_D_VM), $(VM_SRC_LIST))
O_VM		=	$(addprefix $(OBJ_DIR_VM), $(OBJ_VM))

#####################ASM_SOURCES##################################################

ASM_SRC_LIST =	main.c \
				assembler_mode.c \
				asm_split_n_check.c \
				asm_skip.c \
				asm_reader.c \
				asm_writer.c \
				asm_check1.c utils1.c \
				asm_filler.c \
				utils2.c \
				asm_label_operations.c \
				asm_cmd_ops.c \
				utils3.c \
				asm_getsetarg.c \
				asm_types.c

SRC_ASM		= 	$(ASM_SRC_DIR), $(ASM_SRC_LIST))
OBJ_AS		=	$(ASM_SRC_LIST:%.c=%.o)
SRCS_AS		=	$(addprefix $(SRC_L_D_ASM), $(ASM_SRC_LIST))
OBJ_ASM		=	$(addprefix $(OBJ_DIR_ASM), $(OBJ_AS))

all:  $(OBJ_DIR_VM) $(COREWAR) $(OBJ_DIR_ASM) $(ASM)
	@echo " \033[1;37m▆\\033[1;33m▆\\033[1;36m▆\\033[1;32m▆\\033[1;35m▆\\033[1;31m▆\\033[1;34m▆\\033[1;30m▆\033[0m"
	@echo "\\033[33m COREWAR project has been compliled successfully!\033[0m"
	@echo " \033[1;37m▆\\033[1;33m▆\\033[1;36m▆\\033[1;32m▆\\033[1;35m▆\\033[1;31m▆\\033[1;34m▆\\033[1;30m▆\033[0m"

#create obj dir
$(OBJ_DIR_VM):
	@mkdir -p $(OBJ_DIR_VM)

$(OBJ_DIR_ASM):
	@mkdir -p $(OBJ_DIR_ASM)

#create ASM proj
$(ASM): $(LIB_A) $(OBJ_ASM)
	@echo "\\033[32m Preparing assembler for the COREWAR project... \033[0m"
	@$(CC) $(FLAGS) $(INC_ASM) $(OBJ_ASM) $(LIB_A) -o $(ASM)
	@echo "\033[1;36mASM is compliled successfully\033[0m"


#create VM proj
$(COREWAR): $(LIB_A) $(O_VM)
	@echo "\\033[32m Preparing virtual machine for the COREWAR project... \033[0m"
	@$(CC) $(FLAGS) $(INC_VM) $(O_VM) $(LIB_A) -o $(COREWAR)
	@echo "\033[1;36mVM is compliled successfully\033[0m"

#create libc
$(LIB_A):
	@echo "\\033[34m Preparing libft... ☕☕☕ \033[0m"
	@$(MAKE) -sC $(LIB_DIR) CFLAGS="$(CFLAGS)"

#make obj
$(OBJ_DIR_VM)%.o: $(SRC_L_D_VM)%.c $(HEAD_VM) $(LIB_HEAD)
	@$(CC) $(FLAGS) -c $(INC_VM) $< -o $@
$(OBJ_DIR_ASM)%.o: $(SRC_L_D_ASM)%.c $(HEAD_ASM)
	@$(CC) $(FLAGS) -c $(INC_ASM) $< -o $@

#directory: @$(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR_ASM) $(OBJ_DIR_VM) $(LIB_OBJ)
	@echo "\\033[31m Deleting object files...  \033[0m"
	@echo "\\033[31m Object files were deleted! \033[0m"

fclean: clean
	@rm -rf $(COREWAR) $(ASM) $(LIB_A)
	@echo "\\033[31m Deleting $(NAME)... \033[0m"
	@echo " \033[1;31m▆\\033[1;31m▆\\033[1;31m▆\\033[1;31m▆\\033[1;31m▆\\033[1;31m▆\\033[1;31m▆\033[0m"
	@echo "\\033[31m COREWAR project's binaries and .o files were completely deleted. \033[0m"
	@echo " \033[1;31m▆\\033[1;31m▆\\033[1;31m▆\\033[1;31m▆\\033[1;31m▆\\033[1;31m▆\\033[1;31m▆\n\033[0m"
	
re: fclean all
