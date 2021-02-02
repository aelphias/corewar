/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ptr_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:20:44 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/16 16:35:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_gen_ptr_prec_add(t_printf *lstprf, int len)
{
	write(lstprf->fd, "0", len);
	return (len);
}

int			ft_gen_ptr_prec(void *ptr, t_printf *lstprf)
{
	int		len;
	char	*addpart;
	char	*addpartz;
	char	*retn;
	char	*tmp;

	if (!(lstprf->flag & F_PREC) || lstprf->width > lstprf->prec)
		return (0);
	addpart = ft_ulltoa_base((unsigned long long)ptr, 16);
	len = ft_strlen(addpart) + 2;
	if (len >= lstprf->prec)
		len = ft_gen_ptr_prec_add(lstprf, len);
	if (lstprf->flag & F_PREC && lstprf->prec > 0)
	{
		addpartz = ft_strnew(lstprf->prec - len + 2);
		addpartz = (char*)ft_memset(addpartz, '0', lstprf->prec - len + 2);
		tmp = ft_strjoin("0x", addpartz);
		retn = ft_strjoin(tmp, addpart);
		ft_strdel(&tmp);
		write(lstprf->fd, retn, lstprf->prec + 2);
		ft_memdel((void**)&addpartz);
		ft_strdel(&retn);
	}
	ft_strdel(&addpart);
	return (lstprf->prec + 2);
}

int			ft_gen_ptr(void *ptr, t_printf *lstprf)
{
	int		len;
	char	*addpart;
	char	*retn;

	addpart = ft_ulltoa_base((unsigned long long)ptr, 16);
	len = ft_strlen(addpart) + 2;
	retn = ft_strjoin("0x", addpart);
	ft_strdel(&addpart);
	if (len >= lstprf->width)
		write(lstprf->fd, retn, len);
	else
	{
		addpart = ft_strnew(lstprf->width);
		addpart = (char*)ft_memset(addpart, ' ', lstprf->width);
		if (lstprf->flag & F_MINUS)
			ft_strncpy(addpart, retn, len);
		else
			ft_strncpy(addpart + lstprf->width - len, retn, len);
		write(lstprf->fd, addpart, lstprf->width);
		ft_memdel((void**)&addpart);
	}
	ft_strdel(&retn);
	return (len > lstprf->width ? len : lstprf->width);
}

int			ft_gen_ptr_add(t_printf *lstprf, void *var)
{
	char	*addpart;
	char	*retn;

	if (lstprf->flag & F_PREC)
	{
		if (lstprf->prec == 0)
		{
			write(lstprf->fd, "0x", 2);
			return (2);
		}
		else if (var == 0)
		{
			addpart = ft_strnew(lstprf->prec);
			addpart = (char*)ft_memset(addpart, '0', lstprf->prec);
			retn = ft_strjoin("0x", addpart);
			write(lstprf->fd, retn, lstprf->prec + 2);
			ft_memdel((void**)&addpart);
			ft_strdel(&retn);
			return (lstprf->prec + 2);
		}
	}
	return (0);
}

int			ft_ptr_type(t_printf *lstprf)
{
	void	*var;
	int		ret;
	int		retprec;

	lstprf->str++;
	var = va_arg(lstprf->args, void*);
	ret = ft_gen_ptr_add(lstprf, var);
	if (ret)
		return (ret);
	retprec = ft_gen_ptr_prec(var, lstprf);
	if (retprec)
		return (retprec);
	return (ft_gen_ptr(var, lstprf));
}
