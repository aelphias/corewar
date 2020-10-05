/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:04:42 by denis             #+#    #+#             */
/*   Updated: 2020/10/05 09:01:54 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "libft.h"
# include "err_messenger.h"
# include "../../includes/op.h"
# include <unistd.h>
# include <fcntl.h>

# define A 200
# define B 610
# define C 150
# define D 111
# define E 111
# define F 771
# define G 771
# define H 771
# define I 200
# define J 731
# define K 173
# define L 200
# define M 610
# define N 731
# define O 200
# define P 100
# define MAX_ARGS 4
# define MAGIC_LENGTH			(4)
# define T_DIR_SIZE	(int[]){0, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4}
# define OCTAL		(int[]){0, 0, 1, 1, 1, 1, 1, 1 ,1, 0, 1, 1, 0, 1, 1, 0, 1}
# define ARGS_TYPES	(int[]){0, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P}
# define ALLOWED_ARG_CHARS	"abcdefghijklmnopqrstuvwxyz_0123456789-:%"
# define ALLOWED_DIR_CHARS	"0123456789-"
# define ARGS_QTY	(int[]){0, 1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1}

typedef struct			s_op
{
	int					u_id;
	int					inst_id;
	int					pos;
	int					octet;
	int					argu[3];
	int					argutype[3];
	int					is_arg_label_or_not[3];
	int					arg_size[3];
	int					size;
	struct s_op     	*next;
}						t_op;

typedef struct			s_opdasm
{
	char				*name;
	char				**argu;
	struct s_opdasm		*next;
}						t_opdasm;

typedef struct			s_lbl
{
	int					u_id;
	int					pos;
	char				*name;
	struct s_lbl		*next;
}						t_lbl;

typedef struct			s_ddata
{
	int					fd_r;
	int					fd_w;
	int					total_size;
	char				*name;
	char				*cmnt;
	t_opdasm			*op;
}						t_ddata;

typedef struct			s_crw
{
	int					fd_r;
	int					fd_w;
	int					total_size;
	char				*name;
	unsigned			line_q;
	char				*cmnt;
	t_op		    	*op;
	t_lbl				*label;
}						t_crw;

int						call_error(char const *const err);
void					convloop(t_crw *crwdata);
void					free_str_arr(char **s, char ***arr, int flag);
void					checking_the_data(t_crw *crwdata);
void					data_writing(t_crw *data);
int						get_argz(t_op *op, char **argv, int argc, t_crw *crwdata);
int						set_argz(t_op *oper, int argq, int type_allow, char **clnargz);
int						get_inst(t_crw *crwdata, char **tmp, int inst_id, int tmp_len);
int						is_an_instruction_or_not(char *s);
int						get_lbls_instr(t_crw *data, char *s);
int						get_clean_string(t_crw *data, char **dst);
char					*add_spaces(char **s);
char					**ft_strsplit_whitespace(char const *s);
void					set_arg_value(t_op *op, char *arg, int arg_nr, int arg_type);
t_crw					*get_data(t_crw *data);
t_lbl					*set_lbl(t_lbl **label, char *s);
int     				on_same_line(char *s);
void					get_multiple_lines(t_crw *data, char **s, int flag);
void					add_newline(char **s);
void					check_lengths(char *s, int flag);
int						only_admitted_chars(char *allowed, char *arg);
int						check_type(char *arg);
void					assembler_mode(char *name_of_the_file);
void					disassembler_mode(char *name_of_the_file);
t_crw       			*get_asm_data(t_crw *asm_data);
int						get_number(unsigned char *s, int size);
void					*ft_memdup(const void *src, size_t n);

#endif