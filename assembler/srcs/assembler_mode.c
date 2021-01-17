/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:44:53 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/17 17:52:51 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_usage(void)
{
	ft_printf("Usage: ./asm [champion.cor]\n");
	exit(0);
}

void	is_arg_in_end_or_not(t_arg **a, t_arg *b)
{
	t_arg	*start;

	start = *a;
	if (!*a)
	{
		b->next = *a;
		*a = b;
	}
	else
	{
		while (start->next)
			start = start->next;
		start->next = b;
		b->next = 0;
	}
}

unsigned int	argtoi(const char *str)
{
	int				n;
	unsigned	int	res;

	res = 0;
	n = 1;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\r'
			|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		*str == '-' ? n -= 2 : n + 0;
		str++;
	}
	if (*str < '0' && *str > '9')
		return (0);
	while (*str != '\0' && ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (n * res);
}

void	check_namlbl(char *line)
{
	char	*start;

	start = line;
	while (*start)
	{
		if (!ft_strchr(LABEL_CHARS, *start))
		{
			ft_printf("'%c' is forbidden in label-name\n", *start);
			ft_printf("", line);
		}
		start++;
	}
}

void	chcmd(char *line)
{
	int	i;

	i = 0;
	com_tr(line, ';', COMMENT_CHAR);
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR)
			break ;
		else if (line[i] != ' ' && line[i] != '\t')
			call_simple_error(LEX_ERR);
		i++;
	}
}

void	is_cmnd_in_end_or_not(t_crw **a, t_cmnd *command)
{
	t_cmnd	*start;

	if (!(*a)->cmds)
	{
		command->next = (*a)->cmds;
		(*a)->cmds = command;
	}
	else
	{
		start = (*a)->cmds;
		while (start->next)
			start = start->next;
		start->next = command;
		command->next = 0;
	}
}

int	is_comment_or_not(char *line)
{
	char	*start;

	start = line;
	while (*start && (*start == ' ' || *start == '\t'))
		start++;
	if (*start == COMMENT_CHAR || *start == ';')
		return (1);
	return (0);
}

char	*write_in_str(char *line, int fd, int size)
{
	int		i;
	int		j;
	char	*buff;

	j = 4;
	buff = ft_strdup("\"");
	size == COMMENT_LENGTH ? j = 7 : 0;
	line[len_to(line, '.') + j] != ' ' && line[len_to(line, '.') + j] != '"'
		&& line[len_to(line, '.') + j] != '\t' ? call_simple_error(ERR_INV) : 0;
	i = len_to(line, '.') + j - 1;
	while (line[++i] && line[i] != '"')
		line[i] != ' ' && line[i] != '\t' ?
			call_simple_error(LEX_ERR) : 0;
	if (!ft_strchr(line, '"'))
		call_simple_error(ERR_EST);
	i = 0;
	while (!copy_to(line, &buff, ft_strlen(buff), size))
	{
		i += get_next_line(fd, &line);
		if (!line)
			ft_printf("No '\"' symbol", buff);
	}
	!i ? chcmd(line + len_to(line, '"') + ft_strlen(buff))
		: chcmd(line + len_to(line, '"'));
	return (buff);
}

char	*coreparse(int fd, int size, char *cmd)
{
	char	*line;
	char	*start;
	char	*end;
	int		err;

	while ((err = get_next_line(fd, &line)) > 0)
	{
		if (!ft_strstr(line, cmd))
			chcmd(line);
		else if (ft_strstr(line, cmd) && !is_comment_or_not(line))
			break ;
		ft_strdel(&line);
	}
	!err ? call_simple_error("File is empty") : 0;
	err == -1 ? ft_printf("No .s file, it's directory", 0) : 0;
	!line ? call_simple_error(ERR_EST) : 0;
	start = line;
	while (*start && (*start == ' ' || *start == '\t'))
		start++;
	if (ft_strncmp(start, cmd, len_to(start, ' ') - 1) &&
			ft_strncmp(start, cmd, len_to(start, '\t') - 1)
			&& ft_strncmp(start, cmd, len_to(start, '"') - 1))
		call_simple_error(ERR_INV);
	end = write_in_str(line, fd, size);
	return (end);
}

char		**comname(int fd, t_crw **a)
{
	char	*line;
	char	*end;
	char	**arr;

	end = ft_memalloc(1);
	(*a)->name = coreparse(fd, PROG_NAME_LENGTH, NAME_CMD_STRING);
	(*a)->cmnt = coreparse(fd, COMMENT_LENGTH, COMMENT_CMD_STRING);
	while (get_next_line(fd, &line))
		end = join_free(end, line, 1);
	arr = ft_strsplit(end, '\n');
	ft_strdel(&end);
	return (arr);
}

void	check_lenth(char *line, int size)
{
	if ((int)ft_strlen(line) - 2 > size)
	{
		ft_strdel(&line);
		if (size == 2048)
			call_simple_error(LONG_CO);
		call_simple_error(LONG_CO);
	}
}

void		remove_newline(char **line)
{
	char	*buf;

	buf = ft_strndup(*line, ft_strlen(*line) - 1);
	ft_strdel(line);
	*line = ft_strdup(buf);
	ft_strdel(&buf);
}

int		checker_end(char *line, int len2, char **line2)
{
	if (line[len2 + len_to(line + len2, '"') - 1] == '"')
	{
		remove_newline(line2);
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

int				copy_to(char *line, char **line2, int len, int size)
{
	int			len2;
	char		*buf;
	int			check;

	len2 = 0;
	check = 0;
	if (len == 1)
		while (line[len2] && line[len2] != '"')
			len2++;
	if (len == 1)
		len2++;
	if (len_to(line + len2, '"') == 1)
		*line2 = join_free(*line2, "", 0);
	else
	{
		buf = ft_strndup(line + len2, len_to(line + len2, '"') - 1);
		*line2 = join_free(*line2, buf, 1);
	}
	check_lenth(*line2, size);
	if (checker_end(line, len2, line2) == 1)
		return (1);
	ft_strdel(&line);
	return (0);
}

void	ft_what_byte(t_crw **a)
{
	t_cmnd	*start;
	t_arg		*arg;
	int			i;

	i = 0;
	start = (*a)->cmds;
	while (start)
	{
		start->bytenum = i;
		arg = start->in;
		while (arg)
		{
			i += arg->size;
			arg = arg->next;
		}
		i += start->c + 1;
		start = start->next;
	}
}

int	find_label(t_crw *a, char *name, int num)
{
	t_cmnd	*start;
	t_lbl		*label;
	int			i;

	i = -1;
	start = a->cmds;
	while (start && i == -1)
	{
		label = start->lbls;
		while (label && i == -1)
		{
			if (!ft_strcmp(label->name, name))
				i = start->bytenum;
			label = label->next;
		}
		start = start->next;
	}
	i == -1 ? ft_printf("Label \e[1;33m%s\e[0m doesn't exist", name) : 0;
	if (num > i)
		i = -(num - i);
	else
		i -= num;
	return (i);
}

void	parse_codage(t_cmnd **c)
{
	t_arg	*args;
	int		codage;
	int		i;

	codage = 0;
	i = -1;
	args = (*c)->in;
	while (++i < 3)
	{
		if (args)
		{
			codage += args->bin;
			args = args->next;
		}
		codage <<= 2;
	}
	(*c)->c = codage;
}

void	check_commands(t_cmnd *a)
{
	t_cmnd	*start;
	int			count;

	count = 0;
	start = a;
	while (start)
	{
		start = start->next;
		count++;
	}
	if (count == 0)
		call_simple_error(NO_COMM);
}

void		addval(int fd, t_crw **a)
{
	t_cmnd	*start;
	t_arg		*arg;

	validation(fd, a);
	check_commands((*a)->cmds);
	ft_what_byte(a);
	start = (*a)->cmds;
	while (start)
	{
		arg = start->in;
		if (start->c)
			parse_codage(&start);
		while (arg)
		{
			if ((int)arg->val == -1 && arg->lblname)
				arg->val =
					find_label(*a, arg->lblname, start->bytenum);
			arg = arg->next;
		}
		start = start->next;
	}}

void	arg_dirlbl(char *line, int c, int i, t_cmnd **b)
{
	char	*buff;
	t_arg	*a;

	com_tr(line, ';', COMMENT_CHAR);
	if (i + 1 == g_op[c].args_num
			&& ft_strchr(line, COMMENT_CHAR))
		buff = ft_strndup(line + 2, len_to(line + 2, COMMENT_CHAR) - 1);
	else
		buff = ft_strdup(line + 2);
	check_namlbl(buff);
	a = (t_arg*)ft_memalloc(sizeof(t_arg));
	a->size = g_op[c].t_dir_size;
	a->val = -1;
	a->bin = 2;
	a->lblname = ft_strdup(buff);
	is_arg_in_end_or_not(&(*b)->in, a);
	ft_strdel(&buff);
}
void	arg_label(char *line, int c, int i, t_arg **arg)
{
	if (i + 1 == g_op[c].args_num
			&& ft_strchr(line, COMMENT_CHAR))
		(*arg)->lblname =
			ft_strndup(line + 1, len_to(line + 1, COMMENT_CHAR) - 1);
	else
		(*arg)->lblname = ft_strdup(line + 1);
	check_namlbl((*arg)->lblname);
	(*arg)->val = -1;
}

void		parse_arg_ind(char *line, int c, int i, t_cmnd **b)
{
	int		j;
	t_arg	*a;

	j = 0;
	com_tr(line, ';', COMMENT_CHAR);
	a = (t_arg*)ft_memalloc(sizeof(t_arg));
	if (line[0] == LABEL_CHAR)
		arg_label(line, c, i, &a);
	else
	{
		line[0] == '-' ? j += 1 : 0;
		while (line[j] && ft_isdigit(line[j]))
			j++;
		i + 1 != g_op[c].args_num
			&& line[j] ? ft_printf("extra characters near 't_ind' %c", line) : 0;
		i + 1 == g_op[c].args_num ? chcmd(line + j) : 0;
		a->val = argtoi(line);
		a->lblname = 0;
	}
	a->size = IND_SIZE;
	a->bin = 3;
	is_arg_in_end_or_not(&(*b)->in, a);
}

void		parse_arg_dir(char *line, int c, int i, t_cmnd **b)
{
	int		j;
	t_arg	*a;

	if (line[1] == LABEL_CHAR)
		arg_dirlbl(line, c, i, b);
	else
	{
		j = 1;
		if (!ft_isdigit(line[1]) && line[1] != '-')
			ft_printf("bad value for '%'", line);
		if (line[1] == '-')
			j++;
		while (line[j] && ft_isdigit(line[j]))
			j++;
		if (i + 1 != g_op[c].args_num && line[j] != 0)
			ft_printf("extra characters near 't_ind'", line);
		if (i + 1 == g_op[c].args_num)
			chcmd(line + j);
		a = (t_arg*)ft_memalloc(sizeof(t_arg));
		a->size = g_op[c].t_dir_size;
		a->val = argtoi(line + 1);
		a->lblname = 0;
		a->bin = 2;
		is_arg_in_end_or_not(&(*b)->in, a);
	}
}
void	avaargs(int cmd, int index, int *avargs)
{
	if (g_op[cmd].args_types[index] == 3)
	{
		avargs[0] = T_DIR;
		avargs[1] = T_REG;
	}
	else if (g_op[cmd].args_types[index] == 6)
	{
		avargs[0] = T_DIR;
		avargs[1] = T_IND;
	}
	else if (g_op[cmd].args_types[index] == 5)
	{
		avargs[0] = T_REG;
		avargs[1] = T_IND;
	}
	g_op[cmd].args_types[index] == 7 ? avargs[0] = -1 : 0;
	g_op[cmd].args_types[index] == T_DIR ? avargs[0] = T_DIR : 0;
	g_op[cmd].args_types[index] == T_REG ? avargs[0] = T_REG : 0;
	g_op[cmd].args_types[index] == T_IND ? avargs[0] = T_IND : 0;
	avargs[2] = 0;
}

int	check_valid_arg(char *line, int command, int index)
{
	int		av_args[4];
	int		arg;
	int		i;

	arg = -1;
	avaargs(command, index, av_args);
	line[0] == DIRECT_CHAR ? arg = T_DIR : 0;
	line[0] == 'r' ? arg = T_REG : 0;
	ft_isdigit(line[0]) || (line[0] == '-' && ft_isdigit(line[1]))
			|| line[0] == LABEL_CHAR ? arg = T_IND : 0;
	arg == -1 ? call_simple_error(NO_VALA) : 0;
	i = -1;
	while (++i < 3 && av_args[i])
		if (arg == av_args[i] || av_args[0] == -1)
			break ;
	!av_args[i] ? ft_printf("This command can't contain this arg", line) : 0;
	return (arg);
}

void	parse_arg_reg(char *line, int command, int index, t_cmnd **b)
{
	int			i;
	t_arg		*a;

	i = 1;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (index + 1 != g_op[command].args_num && line[i] != 0)
		ft_printf("extra characters near 'r'", line);
	index + 1 == g_op[command].args_num ? chcmd(line + i) : 0;
	if (i > 3)
		ft_printf("So big value for 'r'", line);
	a = (t_arg*)ft_memalloc(sizeof(t_arg));
	a->size = 1;
	a->val = ft_atoi(line + 1);
	a->lblname = 0;
	a->bin = 1;
	is_arg_in_end_or_not(&(*b)->in, a);
}

int			parse_arg(char *line, t_cmnd **b, int command)
{
	int		i;
	char	**args;
	int		valid;

	args = split_for_args(line);
	(*b)->in = 0;
	i = -1;
	while (args[++i])
	{
		com_tr(args[i], ';', COMMENT_CHAR);
		if (args[i][0] == COMMENT_CHAR)
			break ;
		valid = check_valid_arg(args[i], command, i);
		if (valid == T_REG)
			parse_arg_reg(args[i], command, i, b);
		else if (valid == T_IND)
			parse_arg_ind(args[i], command, i, b);
		else
			parse_arg_dir(args[i], command, i, b);
	}
	matclean(args);
	return (1);
}

int	find_command(char *line)
{
	int		i;
	char	*name;
	char	symb;
	char	*buff;

	symb = ' ';
	i = -1;
	com_tr(line, '\t', ' ');
	while (line[++i])
		if (line[i] == DIRECT_CHAR || line[i] == ' ')
			break ;
	line[i] == DIRECT_CHAR ? symb = DIRECT_CHAR : 0;
	buff = ft_strndup(line, len_to(line, symb) - 1);
	name = ft_strtrim(buff);
	i = -1;
	while (symb != -1 && g_op[++i].name)
		if (!ft_strcmp(g_op[i].name, name))
			symb = -1;
	ft_strdel(&buff);
	ft_strdel(&name);
	if (symb == -1)
		return (i);
	call_simple_error(ER_IN_C);
	return (-1);
}

int	ft_count_args(t_cmnd *command)
{
	t_arg	*args;
	int		count_args;

	args = command->in;
	count_args = 0;
	while (args)
	{
		count_args++;
		args = args->next;
	}
	return (count_args);
}

void	manage_args(t_cmnd *command, int num_com, char *line)
{
	int	no_nice_count;

	no_nice_count = ft_count_args(command);
	if (g_op[num_com].args_num > no_nice_count)
		ft_printf("Too few args", line);
	if (g_op[num_com].args_num < no_nice_count)
		ft_printf("Too many args", line);
	if (!no_nice_count)
		call_simple_error(NO_ARGS);
}
int	ft_countwords(char const *str, char c)
{
	int i;
	int count;
	int j;

	i = 0;
	count = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			count++;
		}
		while (str[i] == c && str[i])
			i++;
	}
	return (count);
}

void	parse_commas(char *line, int command)
{
	char	*start;
	int		count;
	char	**arr;

	count = 1;
	start = line;
	while (*start && *start != ';' && *start != COMMENT_CHAR)
	{
		if (*start == SEPARATOR_CHAR)
			count++;
		start++;
	}
	if (count > g_op[command].args_num)
		call_simple_error(COMXTRA);
	if (count < g_op[command].args_num)
		call_simple_error(COM_FEW);
	arr = ft_strsplit(line, SEPARATOR_CHAR);
	count = -1;
	while (count != -2 && arr[++count] && !ft_strchr(arr[count], ';')
			&& !ft_strchr(arr[count], COMMENT_CHAR))
		if (ft_countwords(arr[count], ' ') > 1 ||
				ft_countwords(arr[count], '\t') > 1)
			count = -2;
	matclean(arr);
	count == -2 ? call_simple_error(COM_BAD) : 0;
}

void		parse_command(char *line, t_crw **a, t_lbl *lbls)
{
	int			command;
	t_cmnd	*b;

	if (!ft_strlen(line))
		return ;
	while (*line && (*line == '\t' || *line == ' '))
		line++;
	command = find_command(line);
	line += ft_strlen(g_op[command].name);
	b = (t_cmnd*)ft_memalloc(sizeof(t_cmnd));
	parse_commas(line, command);
	b->name = ft_strdup(g_op[command].name);
	b->in = 0;
	b->c = g_op[command].args_num;
	parse_arg(line, &b, command);
	manage_args(b, command, line);
	b->lbls = lbls;
	b->oper_code = g_op[command].code;
	is_cmnd_in_end_or_not(a, b);
}

int		size_code(t_crw *a)
{
	int			size;
	t_cmnd	*command;
	t_arg		*arg;

	size = 0;
	command = a->cmds;
	while (command)
	{
		if (ft_strcmp(command->name, "-1"))
		{
			size++;
			if (command->c)
				size++;
			arg = command->in;
			while (arg)
			{
				size += arg->size;
				arg = arg->next;
			}
		}
		command = command->next;
	}
	return (size);
}

int	size_command(t_cmnd *command)
{
	int		size;
	t_arg	*args;

	size = 1;
	if (command->c)
		size++;
	args = command->in;
	while (args)
	{
		size += args->size;
		args = args->next;
	}
	return (size);
}

	int	length_w(char const *str)
{
	int length;
	int i;

	length = 0;
	i = 0;
	while (str[i] == ',' || str[i] == '\t' || str[i] == ' ')
		i++;
	while ((str[i] != ',' && str[i] != '\t' && str[i] != ' ') && str[i])
	{
		length++;
		i++;
	}
	return (length);
}

int	countwords(char const *str)
{
	int i;
	int count;
	int j;

	i = 0;
	count = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != ',')
		{
			while (str[i] != ' ' && str[i] != '\t' && str[i] != ',' && str[i])
				i++;
			count++;
		}
		while ((str[i] == '\t' || str[i] == ' ' || str[i] == ',') && str[i])
			i++;
	}
	return (count);
}

char		**split_for_args(char *line)
{
	int		i;
	int		j;
	int		k;
	char	**end;

	if (!line || !(end = (char **)ft_memalloc(sizeof(*end)
					* countwords(line) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < countwords(line))
	{
		k = 0;
		if (!(end[i] = ft_strnew(length_w(&line[j]))))
			return (NULL);
		while (line[j] == '\t' || line[j] == ' ' || line[j] == ',')
			j++;
		while (line[j] != '\t' && line[j] != ' ' && line[j] != ',' && line[j])
			end[i][k++] = line[j++];
		end[i][k] = '\0';
		i++;
	}
	end[i] = 0;
	return (end);
}

void	com_tr(char *line, char c, char c2)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			line[i] = c2;
		i++;
	}
}

int	comparison(char *line)
{
	char	*start;
	int		i;

	start = line;
	while (*start && (*start == '\t' || *start == ' '))
		start++;
	if (*start == COMMENT_CHAR || *start == ';')
		return (0);
	while (*start)
	{
		i = -1;
		while (STR_COMP[++i])
			if (*start == STR_COMP[i])
				return (1);
		start++;
	}
	return (0);
}

int	add_label(char *line, t_lbl **b)
{
	t_lbl	*label;
	char	*start;
	int		i;
	char	*buff;

	com_tr(line, '\t', ' ');
	start = line;
	i = -1;
	while (*start && *start == ' ')
		start++;
	while (start[++i] && start[i] != LABEL_CHAR)
		if (!ft_strchr(line, LABEL_CHAR) || start[i] == ' ' ||
				start[i] == '%' || start[i] == '#' || start[i] == ';')
			return (0);
	buff = ft_strndup(start, len_to(start, LABEL_CHAR) - 1);
	label = (t_lbl*)ft_memalloc(sizeof(t_lbl));
	label->name = ft_strtrim(buff);
	!ft_strlen(label->name) ? call_simple_error(NO_LABE) : 0;
	ft_strdel(&buff);
	check_namlbl(label->name);
	label->next = *b;
	*b = label;
	return (len_to(line, LABEL_CHAR));
}

void	label_in_end_of_file(t_crw **a, t_lbl *label)
{
	t_cmnd	*b;

	b = (t_cmnd*)ft_memalloc(sizeof(t_cmnd));
	b->name = ft_strdup("-1");
	b->lbls = label;
	b->in = 0;
	is_cmnd_in_end_or_not(a, b);
}

void	parse_this(char **arr, t_crw **a, int *index)
{
	t_lbl			*lbls;
	int				i;
	char			*line;

	lbls = 0;
	i = *index - 1;
	while (arr[++i])
	{
		line = arr[i];
		line += add_label(line, &lbls);
		if (ft_strlen(line) && !comparison(line))
			chcmd(line);
		else if (ft_strlen(line))
			break ;
	}
	*index = i;
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	ft_strlen(line) && (i == (int)ft_strlen(line) || !comparison(line)) ?
		chcmd(line) : parse_command(line, a, lbls);
	if (lbls && (i == (int)ft_strlen(line) || !comparison(line)))
		label_in_end_of_file(a, lbls);
}

void		validation(int fd, t_crw **a)
{
	char	**arr;
	int		i;

	i = 0;
	arr = comname(fd, a);
	while (arr[i])
	{
		if (!comparison(arr[i]))
			chcmd(arr[i]);
		else
			parse_this(arr, a, &i);
		if (!arr[i])
			break ;
		i++;
	}
	matclean(arr);
}

int	width(int i, int sym)
{
	char	str[4096];
	int		res;

	res = 0;
	while (i > 0)
	{
		if (i < 4095)
		{
			ft_memset(str, sym, i);
			str[i] = '\0';
			res += i;
			ft_putstr(str);
			break ;
		}
		ft_memset(str, sym, 4095);
		str[4095] = '\0';
		ft_putstr(str);
		ft_strclr(str);
		res += 4095;
		i -= 4095;
	}
	return (res);
}

void		bytewrite(int fd, int a, int count_bytes)
{
	int				j;
	unsigned char	arr[count_bytes];

	j = count_bytes;
	while (count_bytes--)
	{
		arr[count_bytes] = (unsigned char)a;
		a >>= 8;
	}
	while (++count_bytes < j)
		write(fd, &arr[count_bytes], 1);
}

void		write_name_comment(int fd, t_crw *a)
{
	int		i;

	i = 0;
	bytewrite(fd, COREWAR_EXEC_MAGIC, 4);
	while (a->name[++i])
		bytewrite(fd, a->name[i], 1);
	while (++i < 134)
		bytewrite(fd, 0, 1);
	bytewrite(fd, size_code(a), 4);
	i = 0;
	while (a->cmnt[++i])
		bytewrite(fd, a->cmnt[i], 1);
	while (++i < 2054)
		bytewrite(fd, 0, 1);
}

void		writing_command(int fd, t_crw *a)
{
	t_cmnd	*command;
	t_arg		*arg;

	command = a->cmds;
	while (command)
	{
		if (ft_strcmp(command->name, "-1"))
		{
			arg = command->in;
			bytewrite(fd, command->oper_code, 1);
			if (command->c)
				bytewrite(fd, command->c, 1);
			while (arg)
			{
				bytewrite(fd, arg->val, arg->size);
				arg = arg->next;
			}
		}
		command = command->next;
	}
}

void		filewrite(t_crw *a, char *line)
{
	char	*file_name;
	int		fd;
	int		size_file;

	size_file = ft_strlen(line) - 1;
	while (line[size_file] && line[size_file] != '.')
		size_file--;
	if (size_file == -1)
		file_name = ft_strdup(".cor");
	else
		file_name = ft_strndup(line, size_file);
	file_name = join_free(file_name, ".cor", 0);
	file_name[ft_strlen(file_name) - 1] = 0;
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	write_name_comment(fd, a);
	writing_command(fd, a);
	ft_printf("Writing output program to %s\n", file_name);
	close(fd);
	ft_strdel(&file_name);
}

void		main_val(t_crw **ch, int fd)
{
	t_crw	*ch1;
	t_crw	*s;

	ch1 = (t_crw*)ft_memalloc(sizeof(t_crw));
	s = (t_crw*)ft_memalloc(sizeof(t_crw));
	ch1->cmds = 0;
	addval(fd, &ch1);
	close(fd);
	if (!ch1->cmds)
		call_simple_error(NO_COMM);
	if (!*ch)
	{
		ch1->next = *ch;
		*ch = ch1;
	}
	else
	{
		s = *ch;
		s->next = ch1;
		ch1->next = 0;
	}
	close(fd);
}

void		core_init(t_crw *crw)
{
	crw->name = NULL;
	crw->cmnt = NULL;
	crw->cmds->argcount = 0;
	crw->cmds->argz[0] = 0;
	crw->cmds->argz[1] = 0;
	crw->cmds->argz[2] = 0;
	crw->cmds->bytenum = 0;
	crw->cmds->c = 0;
	crw->cmds->oper_code = 0;
	crw->cmds->sizeoflbl = 0;
}

int			assembler_mode(char *nof)
{
	t_crw	*crw;
	int		fd;

	fd = open(nof, O_RDONLY);
	if (fd == -1)
		call_simple_error(ERR_INV);
	if (!(crw = (t_crw*)ft_memalloc(sizeof(t_crw))))
		call_simple_error(MEM_ALL);
	else
	{	
		//core_init(crw);
		main_val(&crw, fd);
		filewrite(crw->next, nof);
	}
	free(nof);
	free(crw);
	return (0);
}
