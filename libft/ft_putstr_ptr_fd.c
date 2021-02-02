/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:44 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 13:35:45 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_ptr_fd(const int fd, char const *start, char const *finish)
{
	if (start && finish && finish > start && fd > 0)
		return (write(fd, start, finish - start));
	return (0);
}
