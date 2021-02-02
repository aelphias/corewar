/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:15:59 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/01 20:10:58 by gjigglyp         ###   ########.fr       */
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

# define LAB_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789%-:"

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
# define ALLOWED_DIR_CHARS		"0123456789-"

# define STR_COMP "r%0123456789:"

typedef struct			s_cmnd
{
	int					id;
	int					cm_id;
	int					cm_code;
	int					pos;
	unsigned int		argument[3];
	int					argtype[3];
	int					arg_is_lbl[3];
	int					argsize[3];
	int					size;
	struct s_cmnd		*next;
}						t_cmnd;

typedef struct			s_lbl
{
	int					id;
	char				*name;
	int					pos;
	struct s_lbl		*next;
}						t_lbl;

typedef struct			s_crw
{
	int					fd;
	char				*af;
	char				*name;
	int					if_name_exist;
	char				*cmnt;
	int					if_cmnt_exist;
	size_t				sf;
	size_t				size_code;
	int					arp;
	int					pos;
	t_cmnd				*cmnd;
	t_cmnd				*last_cmnd;
	t_lbl				*lbl;
	char				string[1000];
}						t_crw;

/*
** list of functions
*/

int						is_fn(const char *fn, const char *ex);
int						assembler_mode(char *nof);
void					print_usage(void);
void					split_n_check(t_crw *crw);
void					tokensplit(t_crw *crw);
void					nonex_lbls(t_crw *crw);
void					nonex_code(t_crw *crw);
t_crw					*init_crw(int fd);
void					call_simple_error(char *error);
void					asm_fileread(int fd, t_crw *crw);
void					strread(t_crw *crw);
void					write_fd(char *av, t_crw *crw);
int						if_is_space(char c);
void					spaceskip(t_crw *crw);
int						cmntskip(t_crw *crw);
void					namecheck(t_crw *crw);
void					cmntcheck(t_crw *crw);
void					lbl_and_cmnd(t_crw *crw);
char					*ft_strjoin_for_asm(char *line, char *line2, int flag);
void					nwrite(t_crw *crw);
void					comwrite(t_crw *crw);
void					cmndwrite(t_crw *crw);
void					bytewrite(int fd, int c, int cb);
void					count_lbl(t_lbl *label, t_cmnd *cmnd);
int						sc(t_cmnd *cmnd);
char					*add_spaces(char *str);
int						wordcount(char *str, int c);
void					fill_word(char const *s, char *word, int start,\
										int stop);
char					**fillaw(char **aw, char *str, int c);
char					**split_string(char *str);
void					free_str_arr(char **str, char ***arr, int flag);
int						is_lbl_or_not(char *word);
void					init_newlbl(t_lbl **tmp, char *word, int id);
t_lbl					*labadd(t_lbl **label, char *word);
void					checklbl(t_crw *crw, char **aw, int nw);
int						is_cmnd_or_not(char *w);
void					count_cmnd_size(t_cmnd *cmnd, int id_cm);
void					check_cmnd(t_crw *crw, char **aw,
										int id_cm, int nw);
void					checkfs(t_crw *crw);
void					fill_name(t_crw *crw);
void					fill_cmnt(t_crw *crw);
t_cmnd					*add_cmnd(t_crw *crw, int id_cm);
int						get_args(t_cmnd *cmnd, char **args, int nb_arg,
								t_crw *crw);
char					**get_clean(char **args, int nb_arg);
void					commcheck(char **args, int an);
void					minch(char **args, int an);
t_cmnd					*init_cm_lst(t_cmnd *cmnd, int id_cm, t_crw *crw);
int						set_args(t_cmnd *cmnd, char **clean_args, int an,\
								t_crw *crw);
void					split_args(char **res, char ***tmp, int nb_arg);
int						setarg(char *arg, int anb, int at, t_crw *crw);
int						is_oac(char *allowed, char *arg);
int						check_type(char *arg);
void					setargnum(t_cmnd *cmnd, char *arg,
								int args_num, int arg_type);
void					ncc_write(t_crw *crw);
void					fill_cmnd_arr(t_cmnd *cmnd, int args_num, int arg_type);

#endif
