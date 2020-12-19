# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 20:15:08 by aelphias          #+#    #+#              #
#    Updated: 2020/12/20 20:07:38 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COREWAR		=	corewar
NAME		=	$(COREWAR)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -g # -Werror

LIB_DIR		=	../libft/
LIB_A		=	$(LIB_DIR)libft.a
LIB_HEAD	=	$(LIB_DIR)libft.h

#name all dir
INC_DIR		=	./includes/
OBJ_DIR		=	./obj/
SRC_L_D		=	./srcs/

HEAD		=	$(INC_DIR)corewar.h
INC			=	-I$(LIB_DIR) -I$(INC_DIR)

SRC_COREWAR =	main.c print_error.c parsing.c parse_flags.c testing.c 
OBJ_AS		=	$(SRC_COREWAR:%.c=%.o)
SRCS_AS		=	$(addprefix $(SRC_L_D), $(SRC_COREWAR))
OBJ_COREWAR		=	$(addprefix $(OBJ_DIR), $(OBJ_AS))

all : $(OBJ_DIR) $(COREWAR)

#create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

#create corewar proj
$(COREWAR): $(LIB_A) $(OBJ_COREWAR)
	@echo "\\033[32m Prepare vm for the COREWAR project... \033[0m"
	@$(CC) $(CFLAGS) $(INC) $(OBJ_COREWAR) $(LIB_A) -o $(COREWAR)

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