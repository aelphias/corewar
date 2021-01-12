/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:47:59 by jigglyp           #+#    #+#             */
/*   Updated: 2021/01/11 11:09:53 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t i)
{
	if (!content || !i)
		return ;
	ft_memdel(content);
	i = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lstnew;
	t_list *begin;

	if (!f || !lst)
		return (0);
	if (lst)
	{
		if (!(begin = ft_lstnew((f(lst))->content, (f(lst))->content_size)))
			return (0);
		lst = lst->next;
		lstnew = begin;
	}
	while (lst)
	{
		if (!(lstnew->next = ft_lstnew((f(lst))->content, \
						(f(lst))->content_size)))
		{
			ft_lstdel(&begin, &del);
			return (NULL);
		}
		lst = lst->next;
		lstnew = lstnew->next;
	}
	return (begin);
}
