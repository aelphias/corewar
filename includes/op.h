/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:09:23 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/23 13:07:12 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H


#define IND_SIZE				2
#define REG_SIZE				4 //размер одного регистра
#define DIR_SIZE				REG_SIZE

/* 
* 1  0000 0001
# 2  0000 0010
# 3  0000 0011
0110 1100
*/
//для get_type_arg
# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4  //
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024) // размер арены
#define IDX_MOD					(MEM_SIZE / 8) /*максимальный прыжок каретки?   = 512*/
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10


typedef char	t_arg_type;

/*
** Why we need this \/ ?
*/

//для get_arg
#define T_REG					1 //Регистр
#define T_DIR					2 //Прямой аргумент 
#define T_IND					4 //непрямой аргумент 
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		header_s
{
	unsigned int		magic;   //big endian //где он находиться в файле?
	char				prog_name[PROG_NAME_LENGTH + 1]; //если размер массива кратно 4м то тогда не будет  лобавляться нулей после, не то добавиться до кратного 4м
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					header_t;
#endif
