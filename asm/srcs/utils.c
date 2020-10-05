/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 21:37:57 by denis             #+#    #+#             */
/*   Updated: 2020/09/28 01:17:09 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_newline(char **s)
{
	char	*tmp;

	tmp = ft_strjoin(*s, "\n");
	free_str_arr(s, NULL, 1);
	*s = tmp;
}

void	check_lengths(char *s, int flag)
{
	if (flag == 1 && ft_strlen(s) > 128)
		exit(!!ft_printf_fd(2, "ERROR: .name too long (%d) > max len (%d)\n",
				ft_strlen(s), PROG_NAME_LENGTH));
	if (flag == 0 && ft_strlen(s) > 2048)
		exit(!!ft_printf_fd(2, "ERROR: .coment too long (%d) > max len (%d)\n",
				ft_strlen(s), COMMENT_LENGTH));
}

int     	on_same_line(char *s)
{
	int		i;
	int		count_quotes;

	i = (int)ft_strlen(s);
	count_quotes = 0;
	while (i > 0 && count_quotes < 2)
	{
		i--;
		if (s[i] == '"')
			count_quotes++;
	}
	if (count_quotes > 1)
		return (1);
	else if (count_quotes > 0)
		return (0);
	else
		return (-1);
}

void	get_multiple_lines(t_crw *data, char **s, int flag)
{
	char	*join_tmp;
	char	*read_tmp;
	char	*quote_pos;

	while (get_next_line(data->fd_r, &read_tmp))
	{
		quote_pos = ft_strchr(read_tmp, '"');
		if (quote_pos != NULL)
			quote_pos[0] = 0;
		data->line_q++;
		if (ft_strstr(read_tmp, NAME_CMD_STRING)
			|| ft_strstr(read_tmp, COMMENT_CMD_STRING))
			exit(!!ft_printf_fd(2, "ERROR: missing closing quote (line %d)\n",
					data->line_q - 1));
		join_tmp = ft_strjoin(*s, read_tmp);
		free_str_arr(s, NULL, 1);
		free_str_arr(&read_tmp, NULL, 1);
		*s = join_tmp;
		join_tmp = 0;
		check_lengths(*s, flag);
		if (quote_pos != NULL)
			break ;
		add_newline(s);
	}
}

int			get_clean_string(t_crw *data, char **dst)
{
	char		*s;
	char		*tmp;
	int			res;
	char		**arr;

	res = get_next_line(data->fd_r, &s);
	tmp = ft_strtrim(s);
	free_str_arr(&s, NULL, 1);
	if (tmp == NULL || ft_strlen(tmp) == 0)
	{
		*dst = ft_strdup("");
		free_str_arr(&tmp, NULL, 1);
		return (res);
	}
	arr = 0;
	if (tmp[0] == COMMENT_CHAR || tmp[0] == ';')
		*dst = ft_strdup("");
	else if (ft_strchr(tmp, COMMENT_CHAR))
		arr = ft_strsplit(tmp, COMMENT_CHAR);
	else
		arr = ft_strsplit(tmp, ';');
	if (arr != 0 && ft_strlen(arr[0]) > 0)
		*dst = ft_strdup(arr[0]);
	free_str_arr(&tmp, &arr, 2);
	return (res);
}

char		*add_spaces(char **s)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = (char*)ft_memalloc(sizeof(char) * 2 * (ft_strlen(*s) + 1));
	i = 0;
	j = 0;
	while (s[0][i])
	{
		if (s[0][i] == '%' || (i > 0 && s[0][i - 1] == ',')
			|| (i > 1 && s[0][i - 1] == ':'
			&& ft_strchr(LABEL_CHARS, s[0][i - 2])))
		{
			tmp[j] = ' ';
			j++;
		}
		tmp[j] = s[0][i];
		j++;
		i++;
	}
	return (tmp);
}

t_crw		*get_data(t_crw *data)
{
	static t_crw *saved_data = 0;

	if (!saved_data)
		saved_data = data;
	return (saved_data);
}

int			only_admitted_chars(char *allowed, char *arg)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(arg);
	while (i < len)
	{
		if (!ft_strchr(allowed, arg[i]))
			return (0);
		i++;
	}
	return (1);
}