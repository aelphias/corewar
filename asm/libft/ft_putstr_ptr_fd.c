/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:49:56 by denis             #+#    #+#             */
/*   Updated: 2020/09/05 19:18:31 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_ptr_fd(const int fd, char const *start, char const *finish)
{
	if (start && finish && finish > start && fd > 0)
		return (write(fd, start, finish - start));
	return (0);
}
