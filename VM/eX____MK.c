/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eX____MK.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:15:08 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/13 19:39:21 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	TODO:
#  0. CHECK for error if you do: make re >>> make: *** No rule to make target `obj', needed by `obj/main.o'.  Stop.
#  1. поставить зависимость от op.h
#  2. поставить зависимость от corewar.h
#
NAME		=	corewar
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

LIB_DIR		=	../libft/
LIB_A		=	$(LIB_DIR)libft.a
LIB_HEAD	=	$(LIB_DIR)libft.h

####################DIRS########################################################

INC_DIR		=	./includes/
OBJ_DIR		=	./obj/
SRC_L_D		=	./srcs/

HEAD		=	$(INC_DIR)corewar.h
INC			=	-I$(LIB_DIR) -I$(INC_DIR)

#####################VM_SOURSES##################################################

VM_SRC_LIST	= print_error.c \
			  parsing.c \
			  parse_flags.c \
			  testing.c \
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
			  get_byte.c\
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
			  get_arg.c
			  #check_winner.c

#SRC_VM		= $(
	 $(VM_SRC_DIR), $(VM_SRC_LIST))
			  


OBJ_VM		=	$(VM_SRC_LIST:%.c=%.o)
SRCS_VM		=	$(addprefix $(SRC_L_D), $(VM_SRC_LIST))
O_VM		=	$(addprefix $(OBJ_DIR), $(OBJ_VM))

all : $(OBJ_DIR) $(NAME)

#create obj dir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#create VM proj
$(NAME): $(LIB_A) $(O_VM)
	echo "\\033[32m Prepare virtual machine for the COREWAR project... \033[0m"
	$(CC) $(CFLAGS) $(INC) $(O_VM) $(LIB_A) -o $(NAME)

#create libc
$(LIB_A):
	echo "\\033[34m Prepare libft... \033[0m"
	$(MAKE) -sC $(LIB_DIR) CFLAGS="$(CFLAGS)"

#make obj
$(OBJ_DIR)%.o: $(SRC_L_D)%.c $(HEAD)
	$(CC) $(CFLAGS) -c $(INC) $< -o $@

directory: $(OBJDIR)

clean:
	rm -rf $(OBJ_DIR) $(LIB_A)
	make -C $(LIB_DIR) clean
	echo "\\033[31m Deleting object files... \033[0m"

fclean: clean
	rm -f $(NAME) $(LIB_A)
	make -C $(LIB_DIR) fclean
	echo "\\033[31m Deleting $(NAME)... \033[0m"

re: fclean all

.PHONY: clean all re pwdfclean directory