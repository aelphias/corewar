# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 13:36:08 by gjigglyp          #+#    #+#              #
#    Updated: 2021/02/02 20:10:31 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

INC = -I ./includes
SOURCES =	ft_abs.c ft_absi.c ft_absll.c ft_apply_flags.c ft_atoi.c ft_atoi_base.c ft_atol.c ft_bubblesort_array.c \
			ft_bzero.c ft_ceil.c ft_clamp.c ft_cmp.c ft_data.c  ft_double_tool.c ft_error.c ft_fclamp.c ft_foreach.c \
			ft_freesplit.c ft_hash.c ft_htoi.c ft_intnew.c ft_delcontent.c ft_is_power_of_x.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isblank.c ft_isdigit.c ft_isempty.c ft_isgraph.c ft_islower.c \
			ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c ft_iswascii.c ft_itoa.c ft_itoa_base.c \
			ft_lennb.c ft_lltoa_base.c ft_lltoa_base_ten.c ft_lstadd.c ft_lstd_collapse.c ft_lstd_del.c \
			ft_lstd_pop_front.c ft_lstd_push_back.c ft_lstd_push_front.c ft_lstdel.c ft_lstdelone.c\
			ft_lstiter.c ft_lstlen.c ft_lstmap.c ft_lstnew.c ft_lstswap.c ft_massize.c ft_max.c ft_memalloc.c\
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memjoin.c ft_memmove.c \
			ft_memset.c ft_memswap.c ft_merge_sort.c ft_min.c ft_nbrlen.c ft_pf_bonus.c \
			ft_pf_colors.c ft_pf_errors.c ft_pf_oct_t.c ft_pf_parse2.c ft_pf_parser.c ft_pf_ptr_t.c ft_pf_str_t.c \
			ft_pf_tools.c ft_pf_uint_t.c ft_pow.c ft_printf.c ft_printing.c ft_putchar.c ft_putchar_fd.c \
			ft_putchar_fd_smpl.c ft_putendl.c ft_putendl_fd.c ft_puthex.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_ptr_fd.c \
			ft_putstr_fd.c ft_putstr_free.c ft_putwchar.c ft_putwstrn_fd.c ft_quick_sort.c ft_rand.c ft_round.c \
			ft_sort_str_table.c ft_str_tools.c ft_str2lower.c ft_strcapitalize.c ft_strcat.c ft_strch.c ft_strchr.c ft_strclr.c \
			ft_strcmp.c ft_strcpy.c ft_strctrim.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			ft_strjoin.c ft_strjoinfree.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strlencmp.c ft_strlowcase.c ft_strmap.c \
			ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnew.c ft_strnjoin.c \
			ft_strjoinfree.c ft_strjoin_free_second.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c \
			ft_strtrim.c ft_strupcase.c ft_strupr.c ft_swap.c ft_tolower.c ft_tools.c ft_toupper.c ft_tree_new.c ft_ulltoa_base.c \
			ft_wcharlen.c ft_wstrdup.c ft_wstrjoin.c ft_wstrlen.c ft_wstrsub.c get_next_line.c int_funcions.c

OBJECTS = $(SOURCES:.c=.o)

ODIR = objects

all: $(ODIR) $(addprefix $(ODIR)/, $(OBJECTS)) $(NAME)

$(NAME):
	ar rc $(NAME) $(addprefix $(ODIR)/, $(OBJECTS))
	ranlib $(NAME)

$(ODIR):
	mkdir $(ODIR)

$(ODIR)/%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $(INC) $< -o $@

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(NAME)

re: all fclean all
