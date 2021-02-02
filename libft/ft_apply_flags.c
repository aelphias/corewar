/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:58:38 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/02/02 18:59:18 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_hex(t_param *param, char *prefix)
{
	if (param->precision == 0 &&
	(param->line_size == 1 && (param->str)[0] == '0'))
	{
		(param->str)[0] = 0;
		param->line_size--;
	}
	if (param->type == 'p')
	{
		prefix[0] = '0';
		prefix[1] = 'x';
	}
	if (param->flag.hash && ((param->type == 'X' || param->type == 'x' ||
	param->type == 'o') && !((param->str)[0] == '0' && param->line_size == 1)))
	{
		if (param->type == 'o')
		{
			if (param->precision < 1)
				prefix[0] = '0';
		}
		else if (param->line_size > 0)
		{
			prefix[0] = '0';
			prefix[1] = (char)param->type;
		}
	}
}

void	apply_sign(t_param *param, char *prefix)
{
	if (param->sign)
		prefix[0] = '-';
	if (param->type == 'd' || param->type == 'i' ||
	param->type == 'f' || param->type == 'e')
	{
		if (param->flag.plus && !param->sign)
			prefix[0] = '+';
		else if (param->flag.space && !param->sign)
			prefix[0] = ' ';
	}
}

void	apply_flag_minus(t_param *p, char *prefix, char *ptr)
{
	char *temp;
	char *temp2;

	if (p->flag.minus)
	{
		temp = ft_memjoin(prefix, p->str, ft_strlen(prefix), p->line_size);
		p->line_size += ft_strlen(prefix);
		ft_memdel((void **)&p->str);
		p->str = ft_memjoin(temp, ptr, p->line_size, ft_strlen(ptr));
		ft_memdel((void **)&temp);
	}
	else if (p->flag.zero)
	{
		p->str = ft_strjoin_free_second(ptr, &p->str);
		p->str = ft_strjoin_free_second(prefix, &p->str);
	}
	else
	{
		temp = ft_strjoin(ptr, prefix);
		temp2 = ft_strjoin(temp, p->str);
		ft_memdel((void **)&p->str);
		ft_memdel((void **)&temp);
		p->str = temp2;
	}
}

void	apply_width(t_param *param, char *prefix, int len)
{
	char	ptr[param->width - len];
	char	space;
	int		i;

	i = -1;
	space = ' ';
	if (param->precision == -1)
		param->precision = param->width;
	if (param->width > 0 && param->flag.zero && !param->flag.minus)
		space = '0';
	while (i++ < param->width - len - 1)
	{
		if (i >= param->width - param->precision)
			ptr[i] = space;
		else
			ptr[i] = ' ';
	}
	ptr[i] = 0;
	apply_flag_minus(param, prefix, ptr);
}

int		ft_apply_flags(t_param *param)
{
	int		len;
	char	*temp;
	char	prefix[3];

	prefix[0] = 0;
	prefix[1] = 0;
	prefix[2] = 0;
	if (param->type == 'X' || param->type == 'x' || param->type == 'o' ||
		param->type == 'p' || param->type == 'd' || param->type == 'i' ||
		param->type == 'u')
		apply_hex(param, prefix);
	apply_sign(param, prefix);
	len = (param->line_size) + ft_strlen(prefix);
	if (param->width < len)
		param->width = len;
	if (len < param->width)
		apply_width(param, prefix, len);
	else
	{
		temp = ft_strjoin(prefix, param->str);
		ft_memdel((void **)&param->str);
		param->str = temp;
	}
	param->line_size = param->width;
	return (1);
}
