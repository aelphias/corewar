/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:33:38 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/03/06 12:33:38 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_median(t_list *source, t_list **first, t_list **second)
{
	t_list *fast;
	t_list *slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
		if ((fast = fast->next))
		{
			slow = slow->next;
			fast = fast->next;
		}
	*first = source;
	*second = slow->next;
	slow->next = NULL;
}

t_list	*ft_merge_sorted(t_list *first, t_list *second, int (*f)())
{
	t_list *result;

	if (!first)
		return (second);
	if (!second)
		return (first);
	if ((*f)(first, second) <= 0)
	{
		result = first;
		result->next = ft_merge_sorted(first->next, second, (*f));
	}
	else
	{
		result = second;
		result->next = ft_merge_sorted(first, second->next, (*f));
	}
	return (result);
}

void	ft_merge_sort_by(t_list **list, int (*f)())
{
	t_list *head;
	t_list *a;
	t_list *b;

	head = *list;
	if ((head == NULL) || (head->next == NULL))
		return ;
	ft_lstd_median(head, &a, &b);
	ft_merge_sort_by(&a, (*f));
	ft_merge_sort_by(&b, (*f));
	*list = ft_merge_sorted(a, b, (*f));
}
