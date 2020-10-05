/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_writing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 00:59:09 by denis             #+#    #+#             */
/*   Updated: 2020/10/04 22:26:36 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void     rewwrite(unsigned char *string, int fd, unsigned full_len)
{
    while(full_len > 0)
    {
        full_len--;
        write(fd, &string[full_len], 1);
    }
}


static void	write_name_comment(char *str, int fd, unsigned total_len)
{
	int		len;
	char	*zeros;

	len = (int)ft_strlen(str);
	zeros = (char*)ft_memalloc(sizeof(char) * (total_len - len + 1));
	write(fd, str, len);
	write(fd, zeros, (total_len - len));
	free_str_arr(&zeros, NULL, 1);
}

void		free_str_arr(char **s, char ***arr, int flag)
{
	int			i;

	if ((flag == 1 || flag == 2) && *s != 0)
	{
		free(*s);
		*s = 0;
	}
	if ((flag == 0 || flag == 2) && arr != 0 && *arr != 0)
	{
		i = 0;
		while (arr[0][i])
		{
			free(arr[0][i]);
			arr[0][i] = 0;
			i++;
		}
		free(*arr);
		*arr = 0;
	}
}
static void	type_selection(int fd, t_op *op, int arg_nr)
{
	unsigned char	c;
	unsigned short	s;
	unsigned int	i;

	if (op->argutype[arg_nr] == 1)
	{
		c = (unsigned char)op->argu[arg_nr];
		rewwrite((unsigned char*)(&c), fd, sizeof(c));
	}
	else if (op->argutype[arg_nr] == 2
		&& T_DIR_SIZE[op->inst_id] == 4)
	{
		i = (unsigned int)op->argu[arg_nr];
		rewwrite((unsigned char*)(&i), fd, sizeof(i));
	}
	else
	{
		s = (unsigned short)op->argu[arg_nr];
		rewwrite((unsigned char*)(&s), fd, sizeof(s));
	}
}

static void	write_op(int fd, t_op *op)
{
	unsigned char	c;
	int				j;

	c = (unsigned char)op->inst_id;
	rewwrite((unsigned char*)(&c), fd, sizeof(c));
	if (op->octet != 0)
	{
		c = (unsigned char)op->octet;
		rewwrite((unsigned char*)(&c), fd, sizeof(c));
	}
	j = 0;
	while (j < ARGS_QTY[op->inst_id])
	{
		type_selection(fd, op, j);
		j++;
	}
}


void		data_writing(t_crw *crwdata)
{
	int			magic;
	int			zero;
	t_op    	*op;

	magic = COREWAR_EXEC_MAGIC;
	zero = 0;
	rewwrite((unsigned char*)(&magic), crwdata->fd_w, sizeof(int));
	write_name_comment(crwdata->name, crwdata->fd_w, PROG_NAME_LENGTH);
	write(crwdata->fd_w, (unsigned char*)(&zero), sizeof(int));
	rewwrite((unsigned char*)(&crwdata->total_size), crwdata->fd_w, sizeof(int));
	write_name_comment(crwdata->cmnt, crwdata->fd_w, COMMENT_LENGTH);
	write(crwdata->fd_w, (unsigned char*)(&zero), sizeof(int));
	op = crwdata->op;
	while (op != NULL)
	{
		write_op(crwdata->fd_w, op);
		op = op->next;
	}
}
