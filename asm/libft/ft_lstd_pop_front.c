/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:32:00 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/07/20 22:17:22 by denis            ###   ########.fr       */
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
