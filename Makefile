# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:51:23 by aelphias          #+#    #+#              #
#    Updated: 2021/01/11 13:14:31 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re pwdfclean directory

COREWAR = asm
COREWAR = corewar
VM_PATH = ./VM/
ASM_PATH = ./asm/

all:  $(COREWAR)

$(ASM):
	make -C $(ASM_PATH)
$(COREWAR):
	make -C $(VM_PATH)
	
clean:
	make -C $(VM_PATH) clean
	
fclean:
	make -C $(VM_PATH) fclean
	
re: fclean all
