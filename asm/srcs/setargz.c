/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setargz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 00:46:38 by denis             #+#    #+#             */
/*   Updated: 2020/10/02 11:06:35 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

void		get_name_comment(t_crw *data, char *s, int flag)
{
	char	**tmp;
	int		one_line;

	tmp = ft_strsplit(s, '"');
	one_line = on_same_line(s);
	if (one_line == -1)
		exit(!!ft_printf_fd(2, "ERROR: no quotes (line %d)\n", data->line_q));
	if (tmp[1])
		s = ft_strdup(tmp[1]);
	else
		s = ft_strdup("");
	if (one_line < 1)
		add_newline(&s);
	if (one_line < 1)
		get_multiple_lines(data, &s, flag);
	check_lengths(s, flag);
	if (flag == 1 && !data->name)
		data->name = s;
	else if (flag == 2 && !data->cmnt)
		data->cmnt = s;
	else
		exit(!!ft_printf_fd(2, "ERROR: redifinition of name or comment\n"));
	free_str_arr(NULL, &tmp, 0);
}

static void	function_choice(t_crw *data, char *tmp)
{
	char	**arr;

	if (ft_strchr(tmp, COMMENT_CHAR))
		arr = ft_strsplit(tmp, COMMENT_CHAR);
	else
		arr = ft_strsplit(tmp, ';');
	if (ft_strlen(tmp) > 0 && tmp[0] != COMMENT_CHAR
		&& tmp[0] != ';')
	{
		if (strncmp(arr[0], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
			get_name_comment(data, arr[0], 1);
		else if (strncmp(arr[0], COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)) == 0)
			get_name_comment(data, arr[0], 2);
		else
			get_lbls_instr(data, arr[0]);
	}
	free_str_arr(NULL, &arr, 0);
}

void			convloop(t_crw *crwdata)
{
	char		*s;

	while (get_clean_string(crwdata, &s) > 0)
	{
		crwdata->line_q++;
		if (ft_strlen(s) > 0)
			function_choice(crwdata, s);
		free_str_arr(&s, NULL, 1);
	}
	free_str_arr(&s, NULL, 1);
}

static int	set_an_arg(t_op *op, char *arg, int arg_nr,	int allowed_type)
{
	int		arg_type;
	int		aux;
	char	*tmp;
	t_crw	*data;
	t_lbl	*label;

	arg_type = check_type(arg);
	aux = (arg_type > 2) + (-1) * (arg_type < -2);
	if (arg_type == 0 || ((arg_type + aux) & allowed_type) == 0
		|| (arg_type == -1 && only_admitted_chars(LABEL_CHARS, &arg[2]) == 0)
		|| (arg_type == -2 && only_admitted_chars(LABEL_CHARS, &arg[2]) == 0)
		|| (arg_type == -3 && only_admitted_chars(LABEL_CHARS, &arg[1]) == 0))
		return (-1);
	if (arg_type < 0)
	{
		tmp = ft_strjoin(&arg[1 + (arg_type > -3)], ":\0");
		data = get_data(NULL);
		label = set_lbl(&data->label, tmp);
		op->is_arg_label_or_not[arg_nr] = label->u_id;
		free_str_arr(&tmp, NULL, 1);
	}
	set_arg_value(op, arg, arg_nr, arg_type);
	op->argutype[arg_nr] = arg_type;
	return (0);
}

int         set_argz(t_op *oper, int argq, int type_allow, char **clnargz)
{
    int		i;

	i = -1;
	while ((++i) + argq < MAX_ARGS)
		type_allow /= 10;
	while (argq > 0)
	{
		argq--;
		if (set_an_arg(oper, clnargz[argq], argq, type_allow % 10)
			< 0)
			return (-1);
		type_allow = type_allow / 10;
	}
	return (1);
}