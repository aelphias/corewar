/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:49 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 13:35:50 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strch(const char *str, int ch)
{
	char *ptr;

	ptr = (char*)str;
	while (*ptr != (char)ch && *ptr)
		++ptr;
	return (ptr);
}
