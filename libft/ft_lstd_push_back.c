/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:35:06 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 13:35:07 by gjigglyp         ###   ########.fr       */
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
