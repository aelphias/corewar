/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:15:59 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 17:19:43 by gjigglyp         ###   ########.fr       */
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

/*
** label structure
*/

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

/*
** basic structure
*/

typedef struct					s_crw
{
	char						name[PROG_NAME_LENGTH + 1];
	char						comment[COMMENT_LENGTH + 1];
	int							code_size;
	unsigned char				*exec_code;
	int							ind_wr;
	int							is_ec;
	int							new_com;
	int							l_size;
	t_lbl						*lbls;
	int							len;
	int							fd;
}								t_crw;

typedef struct					s_dasm
{
	char						*cmd_n;
	unsigned int				arg_type;
	unsigned char				c;
	unsigned int				value;
	unsigned int				a[3];
	unsigned int				dir_size;
}								t_dasm;

void							check_hdr_cases(char **line, t_crw *ch,\
									int *name, int *mc);
void							is_hdr_valid_or_not(int fd, t_crw *ch);
void							is_body_valid_or_not(int fd, t_crw *ch);
void							are_h_and_b_valid_or_not(int fd, t_crw *ch);
void							writelbl(t_crw *ch, int *i, int arg_cntr,\
									char *line);
void							zero_exec(t_crw *ch, int exec_size);
int								get_dir_ind_arg_val(t_crw *ch,\
									char *line, int *i);
int								is_comment_or_not(char *line);
void							spaceskip(int i, char *line, t_crw *ch);
void							while_in_m_comment(t_crw *ch, char **line,\
									int *i, int *j);
int								init_main_com(int *len_const, int *i,\
									char **line, t_crw *ch);
int								is_main_cmnt_or_not(char **line, int fd,\
									t_crw *ch, int mc);
void							if_in_is_label_or_not(t_crw *ch,\
									t_l *new, char *line, int i);
void							init_is_label_or_not(int *i,\
									t_crw *ch, char *line);
int								is_label_or_not(char *line, t_crw *ch);
void							while_is_name(char **line, int *i,\
									t_crw *ch, int *j);
int								is_name(char **line, int fd, t_crw *ch,\
									int name);
int								is_command_or_not(char *line, t_crw *ch);
char							*check_name_com(char *line, t_crw *ch);
int								char_in_lbl(char el);
void							finish_fill_label_range(t_crw *ch);
void							check_type_arg(t_crw *ch);
char							*change_ex(char *filename, char *old,\
									char *new);
int								skip_everything(char *line);
int								cs_count(t_crw *ch);
unsigned char					count_cta(t_crw *ch, int i);
void							free_label(t_lbl label);
void							free_all(t_crw champ);
void							zeroing_values(t_crw *ch, int i, int j);
void							init_crw(t_crw *ch);
void							increase_crw(t_crw *ch);
int								ft_contains(char *str, t_lbl label);
void							while_in_lblfind(t_crw *ch, char *str,\
									int *sum, int i);
void							lblfind(t_crw *ch);
int								find_lab_aft_cmd(t_crw *ch, char *l_name,\
									int start, int arg);
void							if_is_label_or_not(t_crw *ch, int arg_cntr,\
									char *line, int *i);
int								get_reg_arg_val(t_crw *ch, char *line,\
									int *i);
void							if_is_r(int arg_cntr, t_crw *ch,\
									char *line, int *i);
void							if_is_ind(t_crw *ch, int arg_cntr,\
									char *line, int *i);
void							is_lab_in_dir_char(char *line, t_crw *ch,\
									int arg_cntr, int *i);
void							if_is_dir(t_crw *ch, int arg_cntr,\
									char *line, int *i);
int								switching_between_args(char *line,\
									int arg_cntr, t_crw *ch);
void							is_end_comment_or_not(t_crw *ch, char *line);
void							is_file_valid_or_not(char *name, t_crw *ch);
void							write_bin_head(t_crw *ch);
void							proargz(t_crw *ch, int i);
void							excode_write(t_crw *ch);
void							bincodeconvert(t_crw *ch, int fd);
void							writing_4b(t_crw *ch,\
									unsigned int wr);
void							writing_2b(t_crw *ch,\
									unsigned int wr);
void							writing_1b(t_crw *ch,\
									unsigned int wr);
void							print_usage(void);
void							main_val(t_crw *ch, char *nof);
int								assembler_mode(char *nof);
char							*dasm_change_ex(char *filename, char *old,\
									char *new);
char							*find_cmd(t_dasm *dis);
void							check_arg_type(t_dasm *dis, int rd_fd);
void							disasm_header(int wr_fd, int rd_fd);
void							disasm_cmd(int wr_fd, int rd_fd);
void							write_head_elem(char *elem, int cons,\
									int wr_fd, int rd_fd);
void							readval(t_dasm *dis, int rd_fd);
void							read_the_first_value(t_dasm *dis, int rd_fd);
void							write_lbl(int *output, t_dasm *dis,\
									int rd_fd, int wr_fd);
void							write_arg(int wr_fd, t_dasm *dis,\
									int rd_fd, int arg);
int								disassembler_mode(char *nof);
t_crw							*get_asm_data(t_crw *asm_data);
int								is_admitted_filename(const char *fn, const char *ex);
void							free_and_call(t_crw champ, char *err);
char							*ft_dasm_itoa(int n);
int								if_in_conv_com(char **line, t_crw *ch,\
									int *i, t_tw *arg);
void							conv_cmnd(char *line, t_crw *ch);
int								call_simple_error(char const *err);
void							if_prog_length(t_crw *ch, char **line);
void							free_no_name(char **line, t_crw *ch);

#endif
