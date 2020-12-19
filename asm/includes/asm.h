/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:15:59 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/19 15:49:35 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "../includes/op.h"
# include "err_messenger.h"
# include "application.h"

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define ALT_COMMENT			';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char					t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct					s_l
{
	char						name[256];
	struct s_l					*next;
}								t_l;

typedef struct					s_lbl
{
	int							is_label_or_not;
	t_l							*names;
	t_l							*start;
	int							r1;
	int							r2;
	int							r3;
	char						cmd_n[6];
	int							cmd_c;
	int							cmd_t;
	int							arg_1;
	int							arg_2;
	int							arg_3;
	char						l_name_1[256];
	char						l_name_2[256];
	char						l_name_3[256];
	int							t1;
	int							t2;
	int							t3;
	int							arg_now;
}								t_lbl;

typedef struct					s_tw
{
	int							comma;
	int							arg_cntr;
}								t_tw;

typedef struct					s_crw
{
	char						name[PROG_NAME_LENGTH + 1];
	char						comment[COMMENT_LENGTH + 1];
	int							code_size;
	unsigned char				*exec_code;
	int							ind_wr;
	int							is_end_comment;
	int							new_com;
	int							l_size;
	t_lbl						*labels;

	int							len;
	int							fd;
}								t_crw;

typedef struct					s_dasm
{
	char						*cmd_n;
	unsigned int				arg_type;
	unsigned char				c;
	unsigned int				value;
	unsigned int				arg1;
	unsigned int				arg2;
	unsigned int				arg3;
	unsigned int				dir_size;
}								t_dasm;

void							if_is_label_or_not(t_crw *champ, int arg_cntr,\
													char *line, int *i);
void							recording_label(t_crw *champ, int *i,\
													int arg_cntr, char *line);
int								skip_everything(char *line);
void							free_all(t_crw champ, char *str);
int								switch_args(char *line, int arg_cntr,\
													t_crw *champ);
void							increase_array(t_crw *champ);
char							*check_name_com(char *line, t_crw *champ);
int								is_command_or_not(char *line, t_crw *champ);
void							skip_spaces(int i, char *line, t_crw *champ);
int								is_comment(char *line);
int								is_name(char **line, int fd,\
													t_crw *champ, int name);
int								is_main_comment(char **line, int fd,\
													t_crw *champ, int mc);
int								is_command_or_not(char *line,\
													t_crw *champ);
int								find_lab_aft_cmd(t_crw *champ,\
													char *l_name, int start,\
													int arg);
int								is_comment(char *line);
int								is_label_or_not(char *line, t_crw *champ);
void							write_4_byte(t_crw *champ,\
													unsigned int to_write);
void							write_2_byte(t_crw *champ,\
													unsigned int to_write);
void							write_1_byte(t_crw *champ,\
												unsigned int to_write);
void							zero_exec(t_crw *champ, int exec_size);
void							init_array(t_crw *champ);
int								get_reg_arg_val(t_crw *champ,\
													char *line, int *i);
int								char_in_label(char el);
int								get_dir_ind_arg_val(t_crw *champ,\
													char *line, int *i);
void							find_label(t_crw *champ);
void							is_file_valid_or_not(char *name, t_crw *champ);
void							check_type_arg(t_crw *champ);
char							*change_ex(char *filename,\
													char *old, char *new);
void							to_bin_code(t_crw *champ, int fd);
void							finish_fill_label_range(t_crw *champ);
unsigned char					count_code_type_arg(t_crw *champ, int i);
int								count_code_size(t_crw *champ);
char							*ft_itoa_1(int n);
void							write_arg(int wr_fd, t_dasm *dis, \
													int rd_fd, int arg);
void							check_arg_type(t_dasm *dis, int rd_fd);
char							*find_cmd(t_dasm *dis);
void							write_head_elem(char *elem, int cons, \
													int wr_fd, int rd_fd);
void							disasm_header(int wr_fd, int rd_fd);
void							disasm_cmd(int wr_fd, int rd_fd);

void							if_is_label(t_crw *champ, int count_arg, \
													char *line, int *i);
int								skip_everything(char *line);
void							free_all(t_crw champ, char *str);
int								switch_args(char *line, int count_arg, \
													t_crw *champ);
void							increase_array(t_crw *champ);
char							*check_name_com(char *line,\
													t_crw *champ);
int								is_command_or_not(char *line, t_crw *champ);
void							skip_spaces2(int i, char *line);
int								is_comment(char *line);
int								is_name(char **line, int fd,\
													t_crw *champ, int name);
int								is_main_comment(char **line, int fd,\
													t_crw *champ, int mc);
int								is_command_or_not(char *line,\
													t_crw *champ);
int								find_lab_aft_cmd(t_crw *champ, char *l_name,\
													int start, int arg);
int								is_comment(char *line);
int								is_label(char *line, t_crw *champ);
void							write_4_byte(t_crw *champ,\
													unsigned int to_write);
void							write_2_byte(t_crw *champ,\
													unsigned int to_write);
void							write_1_byte(t_crw *champ,\
													unsigned int to_write);
void							init_array(t_crw *champ);
int								char_in_label(char el);
void							find_label(t_crw *champ);
void							is_file_valid_or_not(char *name, t_crw *champ);
void							check_type_arg(t_crw *champ);
char							*dasm_change_ex(char *filename,\
													char *old, char *new);
void							to_bin_code(t_crw *champ, int fd);
void							finish_fill_label_range(t_crw *champ);
unsigned char					count_code_type_arg(t_crw *champ, int i);
int								count_code_size(t_crw *champ);
int								assembler_mode(char *name_of_the_file);
int								disassembler_mode(char *name_of_the_file);
void							writing_four_bytes(t_crw *champ, \
													unsigned int to_write);
void							writing_one_byte(t_crw *champ, \
													unsigned int to_write);
void							writing_two_bytes(t_crw *champ, \
													unsigned int to_write);

#endif
