# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 20:15:08 by aelphias          #+#    #+#              #
#    Updated: 2021/01/11 20:15:566 by gjigglyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	TODO:
#  0. CHECK for error if you do: make re >>> make: *** No rule to make target `obj', needed by `obj/main.o'.  Stop.
#  1. поставить зависимость от op.h
#  2. поставить зависимость от corewar.h
#
NAME		=	corewar
CC			=	gcc
FLAGS		=	-Wall -Wextra -g #-Werror

LIBRARIES_VM= -L$(LIB_DIR) -lft
INCLUDES_VM = -I$(INC_DIR) -I$(LIB_DIR)
LIB_DIR		=	../libft/
LIB_FILE	=	$(LIB_DIR)libft.a
LIB_HEAD	=	$(LIB_DIR)

####################DIRS########################################################

INC_DIR		=	./includes/
VM_SRC_DIR		= ./srcs/

HEAD		=	$(INC_DIR)
INC			=	-I$(LIB_DIR) -I$(INC_DIR)

####################VM_SOURSES##################################################

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
			  op_live.c \
			  op_ld.c \
			  op_st.c \
			  op_add.c \
			  op_sub.c\
			  op_and.c\
			  op_or.c\
			  op_xor.c\
			  op_zjmp.c\
			  op_ldi.c\
			  op_sti.c\
			  op_fork.c\
			  op_lld.c\
			  op_lldi.c\
			  op_lfork.c\
			  op_aff.c\
			  get_op_code.c\
			  update_pos.c \
			  parse_n_flag.c \
			  parse_n_flag_cont.c 

SRC_VM		= $(addprefix $(VM_SRC_DIR), $(VM_SRC_LIST))

####################VM_OBJECTS##################################################

VM_OBJ_DIR = ./obj/
VM_OBJECTS_LIST = $(patsubst %.c, %.o, $(VM_SRC_LIST))
VM_OBJECTS = $(addprefix $(VM_OBJ_DIR), $(VM_OBJECTS_LIST))
#VM_DEPS = $(VM_OBJECTS:.o=.d)

##OBJ_AS		=	$(SRC_VM:%.c=%.o)
##SRCS_AS		=	$(addprefix $(SRC_L_D), $(SRC_VM))
##OBJ_COREWAR		=	$(addprefix $(OBJ_DIR), $(OBJ_AS))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(LIB_FILE) $(VM_OBJECTS)
	@echo "$(GREEN)Preparing VM for the COREWAR project...$(RESET)"
	@$(CC) $(FLAGS) $(LIBRARIES_VM) $(VM_OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(LIB_FILE):
	@echo "$(NAME): $(GREEN)Creating $(LIB_FILE)...$(RESET)"
	@make -sC $(LIB_DIR)

$(VM_OBJ_DIR):
	@mkdir -p $@
	@echo "$(NAME): $(GREEN)$@ was created$(RESET)"

$(VM_OBJ_DIR)%.o : $(VM_SRC_DIR)%.c | $(VM_OBJ_DIR)
	@$(CC) $(FLAGS) -MD -c $(INCLUDES_VM) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

#include $(wildcard $(VM_DEPS))

clean:
	@make -sC $(LIB_DIR) clean
	@rm -rf $(VM_OBJ_DIR)
	@echo "$(NAME): $(RED)$(VM_OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIB_FILE)
	@echo "$(NAME): $(RED)$(LIB_FILE) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all