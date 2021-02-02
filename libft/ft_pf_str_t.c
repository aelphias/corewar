/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_str_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:20:51 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wbytelen(const wchar_t *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		if (*str < 0x80)
			len += 1;
		else if (*str < 0x800)
			len += 2;
		else if (*str < 0x10000)
			len += 3;
		else if (*str < 0x200000)
			len += 4;
		str++;
	}
	return (len);
}

void		ft_wstr_gen_helper(wchar_t *str, t_printf *lstprf, int *char_len, \
		int *byte_len)
{
	char	*addpart;

	addpart = ft_strnew(lstprf->width - *byte_len);
	addpart = (char *)ft_memset(addpart, ' ', lstprf->width - *byte_len);
	if (lstprf->flag & F_MINUS)
	{
		ft_putwstrn_fd(str, *char_len, lstprf->fd);
		write(lstprf->fd, addpart, lstprf->width - *byte_len);
	}
	else
	{
		write(lstprf->fd, addpart, lstprf->width - *byte_len);
		write(lstprf->fd, str, *byte_len);
	}
	ft_memdel((void **)&addpart);
}

int			ft_wstr_gen(wchar_t *str, t_printf *lstprf)
{
	int		char_len;
	int		byte_len;

	char_len = ft_wstrlen_wch(str);
	byte_len = ft_wbytelen(str);
	byte_len = (lstprf->flag & F_PREC && byte_len > lstprf->prec) ? \
				lstprf->prec : byte_len;
	if (byte_len >= lstprf->width)
		ft_putwstrn_fd(str, char_len, lstprf->fd);
	else
		ft_wstr_gen_helper(str, lstprf, &char_len, &byte_len);
	return (byte_len > lstprf->width ? byte_len : lstprf->width);
}

int			ft_str_gen(char *str, t_printf *lstprf)
{
	int		len;
	char	*addpart;

	len = ft_strlen(str);
	len = (lstprf->flag & F_PREC && len > lstprf->prec) ? lstprf->prec : len;
	if (len >= lstprf->width)
		write(lstprf->fd, str, len);
	else
	{
		addpart = ft_strnew(lstprf->width);
		addpart = (char*)ft_memset(addpart, ' ', lstprf->width);
		if (lstprf->flag & F_MINUS)
			ft_strncpy(addpart, str, len);
		else
			ft_strncpy(addpart + lstprf->width - len, str, len);
		write(lstprf->fd, addpart, lstprf->width);
		ft_memdel((void**)&addpart);
	}
	return (len > lstprf->width ? len : lstprf->width);
}

int			ft_str_type(t_printf *lstprf)
{
	void	*retn;

	lstprf->str++;
	retn = va_arg(lstprf->args, void *);
	if (lstprf->flag & F_PREC && !lstprf->prec && !lstprf->width)
		return (0);
	if (!retn)
		return (ft_str_gen("(null)", lstprf));
	if (lstprf->flag & L_L)
		return (ft_wstr_gen(retn, lstprf));
	else
		return (ft_str_gen(retn, lstprf));
}
