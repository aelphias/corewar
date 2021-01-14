/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:39 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 13:35:40 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_ten_base_int(t_param *p)
{
	if (p->type == 'u')
	{
		if (p->length == 'h' + 'h')
			return (ft_itoa_u((unsigned char)va_arg(p->ap, unsigned int), p));
		if (p->length == 'h')
			return (ft_itoa_u((USI)va_arg(p->ap, unsigned int), p));
		if (p->length == 0)
			return (ft_itoa_u((unsigned int)va_arg(p->ap, unsigned int), p));
		if (p->length == 'l')
			return (ft_itoa_u((unsigned long)va_arg(p->ap, uintmax_t), p));
		if (p->length == 'l' + 'l')
			return (ft_itoa_u((uintmax_t)va_arg(p->ap, uintmax_t), p));
		if (p->length == 'z' || p->length == 't')
			return (ft_itoa_u((size_t)va_arg(p->ap, size_t), p));
	}
	return (-1);
}

int	get_item(t_param *param)
{
	if (param->type == '%' || param->type == 's' || param->type == 'r' ||
		param->type == 'k' || param->type == 'c')
		return (string_convertation(param));
	if (param->type == 'd' || param->type == 'i')
		return (ten_base_int(param));
	if (param->type == 'u')
		return (u_ten_base_int(param));
	if (param->type == 'x' || param->type == 'X')
		return (hex_base_int(param));
	if (param->type == 'b' || param->type == 'p' || param->type == 'o')
		return (other_base_int(param));
	return (0);
}
