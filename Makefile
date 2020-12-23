# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:51:23 by aelphias          #+#    #+#              #
#    Updated: 2020/12/19 14:56:23 by gjigglyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
COREWAR = corewar
ASM_FILES =	asm
VM_FILES = 	VM

# имена файлов без расширений

LFT_PATH = ./libft/
SRC_PATH = ./srcs/
OBJ_PATH = ./objects/
INC_PATH = ./includes/

IFLAGS = -I $(LFT_PATH)/includes -I $(INC_PATH)
LFLAGS = -L$(LFT_PATH) -lft
CFLAGS = -Wall -Wextra -Werror

ASM_SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(ASM_FILES)))
VM_SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(VM_FILES)))

ASM_OBJ = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(ASM_FILES)))
VM_OBJ = $(addprefix $(OBJ_PATH), $(addsuffix .o, $(VM_FILES)))

LIBFT = $(LFT_PATH)libft.a
INCL = $(INC_PATH)op.h

.PHONY: all clean fclean re

all: $(ASM) $(corewar)

$(ASM): $(LIBFT) $(OBJ_PATH) $(ASM_OBJ)
	gcc $(CFLAGS) $(IFLAGS) $(LFLAGS) $(ASM_OBJ) -o $(ASM)

$(corewar): $(LIBFT) $(OBJ_PATH) $(VM_OBJ)
	gcc $(CFLAGS) $(IFLAGS) $(LFLAGS) $(VM_OBJ) -o $(corewar)

$(LIBFT):
	make -C $(LFT_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCL)
	gcc $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LFT_PATH) clean

#fclean: clean
#	rm -rf $(ASM)
#	rm -rf $(corewar)
#	make -C $(LFT_PATH) fclean

#re: fclean all