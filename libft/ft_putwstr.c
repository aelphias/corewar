/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:26:55 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/21 17:26:56 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(wchar_t *s)
{
	int		len;

	len = ft_wstrlen((unsigned *)s);
	(!len) ? write(1, "(null)", 6) : write(1, s, len);
	return ((!len) ? 6 : len);
}
