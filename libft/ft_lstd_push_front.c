/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:12 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 13:35:13 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_push_front(t_list_a **head, t_list_a *new)
{
	if (head && new)
	{
		if (*head)
		{
			new->next = *head;
			new->prev = (*head)->prev;
			if ((*head)->prev)
				(*head)->prev->next = new;
			*head = new;
			(*head)->next->prev = *head;
		}
		else
			*head = new;
	}
}
