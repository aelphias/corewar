/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_collapse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:31:41 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/07/20 22:17:01 by denis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_collapse(t_list_a *head)
{
	t_list_a *ptr;

	ptr = NULL;
	if (head && head->next)
	{
		while (head->next && head != ptr)
		{
			if (!ptr)
				ptr = head;
			head = head->next;
		}
		head->next = ptr;
		head->next->prev = head;
	}
	else if (head)
	{
		head->next = head;
		head->next->prev = head;
	}
}
