/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:34:59 by denis             #+#    #+#             */
/*   Updated: 2020/09/05 19:16:48 by gjigglyp         ###   ########.fr       */
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
