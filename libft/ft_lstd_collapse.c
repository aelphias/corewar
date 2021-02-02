/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstd_collapse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:34:45 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 13:34:48 by gjigglyp         ###   ########.fr       */
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
