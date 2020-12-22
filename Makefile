# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 15:38:10 by aelphias          #+#    #+#              #
#    Updated: 2020/12/22 15:54:38 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re pwdfclean directory

COREWAR = corewar
VM_PATH =  ./VM

all:  $(COREWAR)

$(COREWAR):
	make -C $(VM_PATH)
	
clean:
	make -C $(VM_PATH) clean
	
fclean:
	make -C $(VM_PATH) fclean
	
re: fclean all