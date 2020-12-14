/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:32:13 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/07/20 22:22:22 by denis            ###   ########.fr       */
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
