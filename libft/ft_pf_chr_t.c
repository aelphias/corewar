/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_chr_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:20:12 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_chr_gen(char c, t_printf *lstprf)
{
	char	*addpart;

	addpart = ft_strnew(lstprf->width);
	addpart = (char*)ft_memset(addpart, ((lstprf->flag & F_ZERO && c == '%') ? \
			'0' : ' '), lstprf->width);
	if (lstprf->flag & F_MINUS)
		addpart[0] = c;
	else
		addpart[lstprf->width - 1] = c;
	write(lstprf->fd, addpart, lstprf->width);
	ft_memdel((void**)&addpart);
	return (lstprf->width);
}

int			ft_char_type(t_printf *lstprf)
{
	char	retn;
	wint_t	w_retn;

	retn = 0;
	w_retn = 0;
	if (*lstprf->str != '%')
	{
		if (lstprf->flag & L_L)
			w_retn = va_arg(lstprf->args, wint_t);
		else
			retn = (char)va_arg(lstprf->args, int);
	}
	else
		retn = '%';
	lstprf->str++;
	if (lstprf->width <= 1)
		ft_putwchar_fd(retn ? retn : w_retn, lstprf->fd);
	return (lstprf->width <= 1 ? 1 : ft_chr_gen(retn, lstprf));
}
