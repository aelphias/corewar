/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:34:57 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 13:34:58 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_pop_front(t_list_a **head)
{
	t_list_a *ptr;

	ptr = NULL;
	if (head && *head)
	{
		if (!ptr)
			ptr = *head;
		if (ptr != (*head)->next)
			ptr = (*head)->next;
		else
			ptr = NULL;
		if (ptr != NULL)
		{
			ptr->prev = ptr->prev->prev;
			ptr->prev->next = ptr;
		}
		ft_memdel(&((*head)->content));
		ft_memdel((void**)head);
		(*head) = ptr;
	}
}
