/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:14:58 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/10/24 19:15:12 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c < 0x80)
		ft_putchar_fd_smpl(c, fd);
	else if (c < 0x800)
	{
		ft_putchar_fd_smpl((0xC0 | (c >> 6)), fd);
		ft_putchar_fd_smpl(0x80 | (c & 0x3F), fd);
		return (2);
	}
	else if (c < 0x10000)
	{
		ft_putchar_fd_smpl(0xE0 | (c >> 12), fd);
		ft_putchar_fd_smpl(0x80 | ((c >> 6) & 0x3F), fd);
		ft_putchar_fd_smpl(0x80 | (c & 0x3F), fd);
		return (3);
	}
	else if (c < 0x200000)
	{
		ft_putchar_fd_smpl(0xF0 | (c >> 18), fd);
		ft_putchar_fd_smpl(0x80 | ((c >> 12) & 0x3F), fd);
		ft_putchar_fd_smpl(0x80 | ((c >> 6) & 0x3F), fd);
		ft_putchar_fd_smpl(0x80 | (c & 0x3F), fd);
		return (4);
	}
	return (c < 0x80 ? 1 : -1);
}
