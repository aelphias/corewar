/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:32:06 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/07/20 22:22:56 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_push_back(t_list_a **head, t_list_a *new)
{
	if (head && new)
	{
		if (*head)
		{
			new->next = *head;
			new->prev = (*head)->prev;
			new->next->prev = new;
			new->prev->next = new;
		}
		else
			*head = new;
	}
}
