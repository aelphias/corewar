# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:51:23 by aelphias          #+#    #+#              #
#    Updated: 2021/01/10 09:39:18 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re pwdfclean directory

COREWAR = corewar
ASSEMBLER = asm
VM_PATH = ./VM/
ASM_PATH = ./assembler/

all:  $(COREWAR) $(ASSEMBLER)

$(COREWAR):
	make -C $(VM_PATH)

$(ASSEMBLER):
	make -C $(ASM_PATH)
	
clean:
	make -C $(VM_PATH) clean
	make -C $(ASM_PATH) clean
	
fclean:
	make -C $(VM_PATH) fclean
	make -C $(ASM_PATH) fclean
	
re: fclean all
