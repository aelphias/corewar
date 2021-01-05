# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:51:23 by aelphias          #+#    #+#              #
#    Updated: 2021/01/05 16:42:25 by gjigglyp         ###   ########.fr        #
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
	
re: clean fclean all