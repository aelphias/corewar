/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstrn_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:15:07 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/10/24 19:15:09 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwstrn_fd(wchar_t *str, size_t len, int fd)
{
	size_t	bytes;

	bytes = 0;
	if (!str || !len)
		return (0);
	while (*str && len)
	{
		bytes += ft_putwchar_fd(*str++, fd);
		len--;
	}
	return (bytes);
}
