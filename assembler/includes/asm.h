/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:15:59 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/17 14:44:10 by gjigglyp         ###   ########.fr       */
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


# define STR_COMP "r%0123456789:"

/*
** label structure
*/

typedef struct			s_lbl
{
	char				*name;
	struct s_lbl		*next;
}						t_lbl;

/*
** argument structure
*/

typedef struct			s_arg
{
	int					bin;
	int					size;
	unsigned int		val;
	char				*lblname;
	struct s_arg		*next;
}						t_arg;

/*
** label struct
*/

typedef struct			s_cmnd
{
	char				*name;
	int					c;
	int					argcount;
	int					sizeoflbl;
	int					argz[3];
	int					oper_code;
	t_lbl				*lbls;
	int					bytenum;
	t_arg				*in;
	struct s_cmnd		*next;
}						t_cmnd;

/*
** main structure
*/

typedef struct			s_crw
{
	char				*name;
	char				*cmnt;
	t_cmnd				*cmds;
	struct s_crw		*next;
}						t_crw;

/*
** disassembler structure
*/

typedef struct			s_dasm
{
	char				*cmd_n;
	unsigned int		arg_type;
	unsigned char		c;
	unsigned int		val;
	unsigned int		a[3];
	unsigned int		dir_size;
}						t_dasm;

void		free_and_call(t_crw ch, char *err);
int			call_simple_error(char const *err);
int			assembler_mode(char *nof);
void		print_usage(void);
void		is_arg_in_end_or_not(t_arg **a, t_arg *b);
unsigned int	argtoi(const char *str);
void	check_namlbl(char *line);
void	chcmd(char *line);
void	is_cmnd_in_end_or_not(t_crw **a, t_cmnd *cmnd);
int	is_comment_or_not(char *line);
int	countwords(char const *str);
char	*write_in_str(char *line, int fd, int size);
char	*coreparse(int fd, int size, char *cmnd);
char	**comname(int fd, t_crw **a);
void	check_lenth(char *line, int size);
void		remove_newline(char **line);
int		checker_end(char *line, int len2, char **line2);
int				copy_to(char *line, char **line2, int len, int size);
void	ft_what_byte(t_crw **a);
int	find_label(t_crw *a, char *name, int num);
void	parse_codage(t_cmnd **c);
void	check_commands(t_cmnd *a);
char	*join_free(char *line, char *line2, int flag);
void		addval(int fd, t_crw **a);
int	len_to(char *str, char c);
void	matclean(char **matrix);
void	arg_dirlbl(char *line, int c, int i, t_cmnd **b);
void	arg_label(char *line, int c, int i, t_arg **arg);
void		parse_arg_ind(char *line, int c, int i, t_cmnd **b);
void		parse_arg_dir(char *line, int c, int i, t_cmnd **b);
void	avaargs(int command, int index, int *av_args);
int	check_valid_arg(char *line, int command, int index);
void	parse_arg_reg(char *line, int command, int index, t_cmnd **b);
int			parse_arg(char *line, t_cmnd **b, int command);
int	find_command(char *line);
int	ft_count_args(t_cmnd *cmnd);
void	manage_args(t_cmnd *cmnd, int num_com, char *line);
void	parse_commas(char *line, int command);
void		parse_command(char *line, t_crw **a, t_lbl *lbls);
int		size_code(t_crw *a);
int	size_command(t_cmnd *cmnd);
int	length_w(char const *str);
char		**split_for_args(char *line);
void	com_tr(char *line, char c, char c2);
int	comparison(char *line);
int	add_label(char *line, t_lbl **b);
void	label_in_end_of_file(t_crw **a, t_lbl *label);
void	parse_this(char **arr, t_crw **a, int *index);
void		validation(int fd, t_crw **a);
int			width(int i, int sym);
void		bytewrite(int fd, int a, int count_bytes);
void		write_name_comment(int fd, t_crw *a);
void		main_val(t_crw **ch, int fd);
int			assembler_mode(char *nof);
int			disassembler_mode(char *nof);
char		*dasm_change_ex(char *filename, char *old,\
									char *new);
void		disasm_header(int wr_fd, int rd_fd);
void		disasm_chcmd(int wr_fd, int rd_fd);
int			ft_countwords(char const *str, char c);
void		write_head_elem(char *elem, int cons, int wr_fd, int rd_fd);
void		read_the_first_value(t_dasm *dis, int rd_fd);
void		write_lbl(int *output, t_dasm *dis, int rd_fd, int wr_fd);
void	check_arg_type(t_dasm *dis, int rd_fd);
void		write_arg(int wr_fd, t_dasm *dis, int rd_fd, int arg);
char	*find_chcmd(t_dasm *dis);
char		*ft_dasm_itoa(int n);


#endif
