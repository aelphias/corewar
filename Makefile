# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:51:23 by denis             #+#    #+#              #
#    Updated: 2020/12/14 19:01:15 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = asm
NAME2 = corewar
ASM_FILES =	asm\

VM_FILES = 	corewar\
			testhello\

# имена файлов без расширений

LFT_PATH = ./libft/
SRC_PATH = ./sources/
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

all: $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(OBJ_PATH) $(ASM_OBJ)
	gcc $(CFLAGS) $(IFLAGS) $(LFLAGS) $(ASM_OBJ) -o $(NAME1)

$(NAME2): $(LIBFT) $(OBJ_PATH) $(VM_OBJ)
	gcc $(CFLAGS) $(IFLAGS) $(LFLAGS) $(VM_OBJ) -o $(NAME2)

$(LIBFT):
	make -C $(LFT_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCL)
	gcc $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LFT_PATH) clean

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	make -C $(LFT_PATH) fclean

re: fclean all