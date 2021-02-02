/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_uint_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:21:00 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*gen_help(t_printf *lstprf, int len)
{
	char				*temp;

	temp = NULL;
	lstprf->flag & F_PREC && len > lstprf->prec ? lstprf->flag &= ~F_ZERO : 0;
	if (lstprf->flag & F_PREC && lstprf->prec > len)
		temp = ft_strnewc(lstprf->prec - len, '0');
	else if (lstprf->flag & F_ZERO && lstprf->width > len)
		temp = ft_strnewc(lstprf->width - len, '0');
	return (temp);
}

int						ft_gen_unsgn(unsigned long long in, t_printf *lstprf)
{
	char				*addpart;
	char				*retn;
	char				*prefix;
	int					len;

	(!in && lstprf->flag & F_PREC && !lstprf->prec) ? addpart = \
		ft_strdup("") : (addpart = ft_ulltoa_base(in, 10));
	prefix = gen_help(lstprf, ft_strlen(addpart));
	retn = ft_strjoin(prefix ? prefix : "", addpart);
	ft_strdel(&prefix);
	ft_strdel(&addpart);
	if ((len = ft_strlen(retn)) >= lstprf->width)
		write(lstprf->fd, retn, len);
	else
	{
		addpart = ft_strnewc(lstprf->width, ' ');
		(lstprf->flag & F_MINUS) ? ft_memcpy(addpart, retn, len) : \
			ft_strcpy(addpart + lstprf->width - len, retn);
		write(lstprf->fd, addpart, lstprf->width);
		ft_strdel(&addpart);
	}
	ft_strdel(&retn);
	return (len > lstprf->width ? len : lstprf->width);
}

int						ft_unsgn_type(t_printf *lstprf)
{
	unsigned long long	retn;

	lstprf->str++;
	if (lstprf->flag & L_HH)
		retn = (unsigned char)va_arg(lstprf->args, int);
	else if (lstprf->flag & L_H)
		retn = (unsigned short)va_arg(lstprf->args, int);
	else if (lstprf->flag & L_L)
		retn = va_arg(lstprf->args, unsigned long);
	else if (lstprf->flag & L_LL)
		retn = va_arg(lstprf->args, unsigned long long);
	else
		retn = va_arg(lstprf->args, unsigned int);
	return (ft_gen_unsgn(retn, lstprf));
}
