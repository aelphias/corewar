/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:08:00 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/03/02 16:08:17 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(const t_list *list)
{
	int		len;

	len = 0;
	if (!list)
		return (0);
	while ((list = list->next))
		len++;
	return (len + 1);
}

int	ft_lstdlen(const t_list *list)
{
	int		len;
	t_list	*ptr;

	len = 0;
	ptr = NULL;
	if (list)
	{
		len++;
		if (list != list->next)
			while (list && list->next != ptr)
			{
				if (!ptr)
					ptr = (t_list*)list;
				list = list->next;
				len++;
			}
	}
	return (len);
}
