# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:51:23 by aelphias          #+#    #+#              #
#    Updated: 2020/12/23 20:34:15 by kcharlet         ###   ########.fr        #
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