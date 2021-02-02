/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:31:35 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/09/05 19:19:03 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_forward_list	*ft_lstappend_frwd(t_forward_list *head, t_forward_list *new)
{
	t_forward_list *ptr;

	ptr = head;
	if (new && head)
		if (head)
		{
			while ((head)->next)
				head = (head)->next;
			(head)->next = new;
			return (ptr);
		}
	return (new);
}
