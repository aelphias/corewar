/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:35:41 by denis             #+#    #+#             */
/*   Updated: 2020/10/05 09:03:40 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char			*set_nam_dasm(unsigned c)
{
	static char **names = 0;

	if (names == 0)
	{
		names = (char**)ft_memalloc(sizeof(char*) * 18);
		names[0] = "wrong \0";
		names[1] = "live \0";
		names[2] = "ld \0";
		names[3] = "st \0";
		names[4] = "add \0";
		names[5] = "sub \0";
		names[6] = "and \0";
		names[7] = "or \0";
		names[8] = "xor \0";
		names[9] = "zjmp \0";
		names[10] = "ldi \0";
		names[11] = "sti \0";
		names[12] = "fork \0";
		names[13] = "lld \0";
		names[14] = "lldi \0";
		names[15] = "lfork \0";
		names[16] = "aff \0";
	}
	return (ft_strdup(names[c]));
}

static t_opdasm		*set_new_op_d(t_ddata *crwdata)
{
	t_opdasm		*op;

	if (crwdata->op == NULL)
	{
		crwdata->op = (t_opdasm*)ft_memalloc(sizeof(t_opdasm));
		op = crwdata->op;
	}
	else
	{
		op = crwdata->op;
		while (op->next != NULL)
			op = op->next;
		op->next = (t_opdasm*)ft_memalloc(sizeof(t_opdasm));
		op = op->next;
	}
	return (op);
}

static char	*set_output_name(char *s)
{
	char	*name;
	char	**tmp;

	if (ft_strlen(s) < 1)
		exit(!!ft_printf_fd(2, "ERROR: output file name not defined\n"));
	tmp = ft_strsplit(s, '.');
	if (ft_strlen(tmp[0]) > 0)
		name = ft_strjoin(tmp[0], ".s");
	else
		name = ft_strdup(".s");
	if (ft_strlen(name) < 1)
		exit(!!ft_printf_fd(2, "ERROR: output file name couldn't be set\n"));
	free_str_arr(NULL, &tmp, 0);
	return (name);
}

t_ddata		*get_dasm_data(t_ddata *dasm_data)
{
	static t_ddata *saved_data = 0;

	if (!saved_data)
		saved_data = dasm_data;
	return (saved_data);
}

static int			get_val_d(char **args, int arg_nr, unsigned octet, int c)
{
	unsigned char	s[4];
	char			**tmp;
	int				value;
	int				type;
	int				size;

	type = (octet == 0) ? 2 : ((octet >> (4 - arg_nr * 2)) & 3);
	size = (type == 2) ? (T_DIR_SIZE[c]) : 2;
	size = (type == 1) ? 1 : size;
	c = (int)read(get_dasm_data(NULL)->fd_r, s, size);
	if (c != size && (int)ft_strlen((char*)s) != size)
		exit(!!ft_printf_fd(2, "ERROR: couldn't read argument value\n"));
	value = get_number(s, size);
	tmp = (char**)ft_memalloc(sizeof(char*) * 3);
	tmp[1] = ft_itoa(value);
	tmp[0] = args[arg_nr];
	if (ft_strlen(args[arg_nr]) == 0)
		args[arg_nr] = ft_strdup(tmp[1]);
	else
		args[arg_nr] = ft_strjoin(tmp[0], tmp[1]);
	free_str_arr(NULL, &tmp, 0);
	return (c);
}

static int			get_args_dasm(t_opdasm *op, unsigned oct, int arg_qt, int opc)
{
	int		i;
	char	*tmp;
	int		size;

	op->argu = (char**)ft_memalloc(sizeof(char*) * (arg_qt + 1));
	i = 0;
	size = 0;
	while (i < arg_qt)
	{
		if (oct != 0 && ((oct >> (4 - i * 2)) & 3) == 1)
			op->argu[i] = ft_strdup("r");
		else if ((oct != 0 && ((oct >> (4 - i * 2)) & 3) == 2) || oct == 0)
			op->argu[i] = ft_strdup("%");
		else
			op->argu[i] = ft_strdup("");
		size += get_val_d(op->argu, i, oct, opc);
		if (i > 0)
		{
			tmp = ft_strjoin(",", op->argu[i]);
			free_str_arr(&(op->argu[i]), NULL, 1);
			op->argu[i] = tmp;
		}
		i++;
	}
	return (size);
}

void				    get_instdasm(t_ddata *data, int opcod, int *data_size)
{
	t_opdasm		    *op;
	unsigned char		s;
	size_t				ret;

	op = set_new_op_d(data);
	if (op == NULL)
		exit(!!ft_printf_fd(2, "ERROR: operation struct wasn't allocated\n"));
	op->name = set_nam_dasm(opcod);
	if (OCTAL[opcod] != 0)
	{
		ret = read(data->fd_r, &s, 1);
		*data_size -= ret;
		*data_size -= get_args_dasm(op, (unsigned)(s >> 2), ARGS_QTY[opcod], opcod);
	}
	else
		*data_size -= get_args_dasm(op, 0, ARGS_QTY[opcod], opcod);
}

static void	get_header(t_ddata *data)
{
	unsigned char	s[COMMENT_LENGTH + 1];
	size_t			ret;

	ret = read(data->fd_r, (void*)s, 4);
	if (ret < MAGIC_LENGTH || get_number(s, MAGIC_LENGTH) != COREWAR_EXEC_MAGIC)
		exit(!!ft_printf_fd(2, "ERROR: file being read has wrong signature\n"));
	ft_bzero((void*)s, COMMENT_LENGTH + 1);
	ret = read(data->fd_r, s, PROG_NAME_LENGTH);
	if (ret < PROG_NAME_LENGTH)
		exit(!!ft_printf_fd(2, "ERROR: file being read is too small\n"));
	data->name = ft_memdup(s, PROG_NAME_LENGTH + 1);
	ret = read(data->fd_r, s, 8);
	if (ret < 8 || ((int*)s)[0] != 0)
		exit(!!ft_printf_fd(2, "ERROR: file being read is corrupt\n"));
	data->total_size = (int)get_number(&s[4], sizeof(int));
	ft_bzero((void*)s, COMMENT_LENGTH + 1);
	ret = read(data->fd_r, s, COMMENT_LENGTH);
	if (ret < COMMENT_LENGTH)
		exit(!!ft_printf_fd(2, "ERROR: file being read is too small\n"));
	data->cmnt = ft_memdup(s, COMMENT_LENGTH + 1);
	ret = read(data->fd_r, s, 4);
	if (ret < 4 || ((int*)s)[0] != 0)
		exit(!!ft_printf_fd(2, "ERROR: file being read is corrupt\n"));
}



static void	convloop_dasm(t_ddata *dasm_data)
{
	unsigned char	s;
	int				data_size;
	size_t			ret;

	get_header(dasm_data);
	data_size = dasm_data->total_size;
	ret = 1;
	while (ret > 0)
	{
		s = 0;
		ret = read(dasm_data->fd_r, &s, 1);
		data_size -= ret;
		if (ret < 1)
			break ;
		if (s < 1 || s > 16)
			exit(!!ft_printf_fd(2, "ERROR: %d is not a valid opcode\n", s));
		get_instdasm(dasm_data, (int)s, &data_size);
	}
	if (data_size != 0)
		exit(!!ft_printf_fd(2, "ERROR: champions' exec. code-size is wrong\n"));
}

static void		data_writing_dasm(int fd, char *name, char *comment, t_opdasm *op)
{
	write(fd, ".name \"", 7);
	write(fd, name, ft_strlen(name));
	write(fd, "\"\n.comment \"", 12);
	write(fd, comment, ft_strlen(comment));
	write(fd, "\"\n\n", 3);
	while (op)
	{
		write(fd, op->name, ft_strlen(op->name));
		while (op->argu[0])
		{
			write(fd, op->argu[0], ft_strlen(op->argu[0]));
			(op->argu)++;
		}
		write(fd, "\n", 1);
		op = op->next;
	}
}

void       disassembler_mode(char *name_of_the_file)
{
	t_ddata	*data;

	data = (t_ddata*)ft_memalloc(sizeof(t_ddata));
	get_dasm_data(data);
	data->fd_r = open(name_of_the_file, O_RDONLY);
	if (data->fd_r < 3 || read(data->fd_r, data->name, 0) < 0)
		exit(!!ft_printf_fd(2, "ERROR: file %s couldn't be read\n",
							name_of_the_file));
	convloop_dasm(data);
	name_of_the_file = set_output_name(name_of_the_file);
	data->fd_w = open(name_of_the_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (data->fd_w < 3)
		exit(!!ft_printf_fd(2, "ERROR: file %s was not created\n", name_of_the_file));
	data_writing_dasm(data->fd_w, data->name, data->cmnt, data->op);
	ft_printf("Writing output program to %s\n", name_of_the_file);
	close(data->fd_w);
	close(data->fd_r);
}
