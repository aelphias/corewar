# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 21:36:22 by denis             #+#    #+#              #
#    Updated: 2020/11/26 23:43:27 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM			=	asm
NAME		=	$(ASM)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIB_DIR		=	./libft/
LIB_A		=	$(LIB_DIR)libft.a
LIB_HEAD	=	$(LIB_DIR)libft.h

#name all dir
INC_DIR		=	./includes/
OBJ_DIR		=	./obj/
SRC_L_D		=	./srcs/

HEAD		=	$(INC_DIR)asm.h
INC			=	-I$(LIB_DIR) -I$(INC_DIR)

SRC_ASM 	=	main.c asm_check_command.c asm_check_comment.c asm_check_labels.c asm_check_names.c \
				asm_checking.c asm_counters.c asm_initialization_free.c asm_label_manipulations.c \
				asm_label_manipulations2.c asm_switching_between_args.c asm_valid_check.c asm_writing_binaries.c \
				asm_writing_by_bytes.c assembler_mode.c dasm_find_n_check.c dasm_header_n_cmds.c \
				dasm_writing_mainpulations.c disassembler_mode.c
OBJ_AS		=	$(SRC_ASM:%.c=%.o)
SRCS_AS		=	$(addprefix $(SRC_L_D), $(SRC_ASM))
OBJ_ASM		=	$(addprefix $(OBJ_DIR), $(OBJ_AS))

all : $(OBJ_DIR) $(ASM)

#create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

#create asm proj
$(ASM): $(LIB_A) $(OBJ_ASM)
	@echo "\\033[32m Prepare assembler for the COREWAR project... \033[0m"
	@$(CC) $(CFLAGS) $(INC) $(OBJ_ASM) $(LIB_A) -o $(ASM)

#create libc
$(LIB_A):
	@echo "\\033[34m Prepare libft... \033[0m"
	@$(MAKE) -sC $(LIB_DIR) CFLAGS="$(CFLAGS)"

#make obj
$(OBJ_DIR)%.o: $(SRC_L_D)%.c $(HEAD)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@

directory: $(OBJDIR)

clean:
	@rm -rf $(OBJ_DIR) $(LIB_A)
	@make -C $(LIB_DIR) clean
	@echo "\\033[31m Deleting object files... \033[0m"

fclean: clean
	@rm -f $(NAME) $(LIB_A)
	@make -C $(LIB_DIR) fclean
	@echo "\\033[31m Deleting $(NAME)... \033[0m"

re: fclean all

.PHONY: clean all re pwdfclean directory