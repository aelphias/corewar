/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:09:50 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/03/02 14:10:09 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_date_sep(char ch)
{
	if (ch == '-')
		return (ch);
	return (0);
}

int		valid_data_input(char *string)
{
	int len;
	int i;

	i = -1;
	len = ft_strlen(string);
	if (len != 10)
		return (0);
	while (++i < len)
	{
		if (i != 4 && i != 7)
		{
			if (ft_isdigit(string[i]) == -1)
				return (0);
		}
		else if (!is_date_sep(string[i]))
			return (0);
	}
	return (1);
}

t_date	*string_to_date(char *str)
{
	t_date *date;

	if (!(date = (t_date*)malloc(sizeof(t_date))))
		return (NULL);
	date->error = 1;
	if (valid_data_input(str))
	{
		date->year = (str[0] - '0') * 1000 + (str[1] - '0') * 100 +
								(str[2] - '0') * 10 + str[3] - '0';
		date->sep = str[4];
		date->month = (unsigned char)((str[5] - '0') * 10 + (str[6] - '0'));
		date->day = (unsigned char)((str[8] - '0') * 10 + (str[9] - '0'));
		if (date->day > 31 || date->month > 12)
			return (date);
		if (date->day > 30 && (date->month == 4 ||
		date->month == 6 || date->month == 9 || date->month == 11))
			return (date);
		if (date->day > 29 && date->month == 2)
			return (date);
		if (date->day > 28 && date->month == 2 &&
			(date->year % 400 && (date->year % 4 && date->year % 100)))
			return (date);
		date->error = 0;
	}
	return (date);
}

void	padding_date_string(char *ptr, t_date *date)
{
	ptr[0] = (char)((date->year / 1000) % 10 + '0');
	ptr[1] = (char)((date->year / 100) % 10 + '0');
	ptr[2] = (char)((date->year / 10) % 10 + '0');
	ptr[3] = (char)(date->year % 10 + '0');
	ptr[4] = (char)date->sep;
	ptr[5] = (char)(date->month / 10 + '0');
	ptr[6] = (char)(date->month % 10 + '0');
	ptr[7] = (char)date->sep;
	ptr[8] = (char)(date->day / 10 + '0');
	ptr[9] = (char)(date->day % 10 + '0');
	ptr[10] = 0;
}

int		date_to_string(t_date *date, t_param *param)
{
	char	ptr[11];
	char	*temp;

	if (date)
	{
		if (date->error)
		{
			temp = ft_strjoin(param->str,
					RED"Invalid date" RESET ": use YYYY-MM-DD format!\n");
			ft_memdel((void**)&param->str);
			param->str = temp;
			param->line_size = ft_strlen(param->str);
			ft_memdel((void**)&date);
			return (1);
		}
		padding_date_string(ptr, date);
		temp = ft_strjoin(param->str, ptr);
		ft_memdel((void**)&param->str);
		param->str = temp;
		param->line_size = ft_strlen(param->str);
		ft_memdel((void**)&date);
	}
	return (0);
}
