/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:20:00 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/03/02 14:30:13 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_flag(const char *str, t_flag *flag)
{
	if (*str == '-')
		flag->minus = 1;
	else if (*str == '+')
		flag->plus = 1;
	else if (*str == '0')
		flag->zero = 1;
	else if (*str == ' ')
		flag->space = 1;
	else if (*str == '#')
		flag->hash = 1;
	else
		return (0);
	return (1);
}

int				get_width(char **str, t_param *param)
{
	int width;

	if (**str == '*')
	{
		(*str)++;
		width = (int)va_arg(param->ap, int);
		if (width < 0)
		{
			param->flag.minus = 1;
			param->width = -width;
		}
		else
			param->width = width;
	}
	if ((width = ft_atoi(*str)))
	{
		param->width = width;
		(*str) += ft_nbrlen(width);
	}
	return (1);
}

int				get_precision(char **str, t_param *param)
{
	int precision;

	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			(*str)++;
			precision = (int)va_arg(param->ap, int);
			param->precision = (precision < 0 ? -1 : precision);
		}
		else if ((param->precision = ft_atoi(*str)) || (**str == '0'))
			(*str) += ft_nbrlen(param->precision);
	}
	return (1);
}

unsigned char	get_length(const char *str)
{
	if (*str == 'h')
	{
		if (*(str + 1) == 'h')
			return ('h' + 'h');
		return ('h');
	}
	if (*str == 'l')
	{
		if (*(str + 1) == 'l')
			return ('l' + 'l');
		return ('l');
	}
	if (*str == 'L')
		return ('L');
	if (*str == 'z')
		return ('z');
	if (*str == 't')
		return ('t');
	return (0);
}

char			get_type(const char *str)
{
	if (*str == '%' || *str == 'd' || *str == 'i' || *str == 'u' ||
		*str == 'c' || *str == 's' || *str == 'p' || *str == 'x' ||
		*str == 'X' || *str == 'f' || *str == 'o' || *str == 'b' ||
		*str == 'e' || *str == 'k' || *str == 'r')
		return (*str);
	return (0);
}
