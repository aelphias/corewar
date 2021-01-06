# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:51:23 by aelphias          #+#    #+#              #
#    Updated: 2021/01/06 16:05:28 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re pwdfclean directory

COREWAR = corewar
VM_PATH = ./VM/

all:  $(COREWAR)

$(COREWAR):
	make -C $(VM_PATH)
	
clean:
	make -C $(VM_PATH) clean
	
fclean:
	make -C $(VM_PATH) fclean
	
re: fclean all
