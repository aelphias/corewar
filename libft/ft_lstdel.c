/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:24:36 by jigglyp           #+#    #+#             */
/*   Updated: 2021/01/11 11:09:53 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *copy;

	if (*alst || del)
	{
		while ((*alst) != NULL)
		{
			copy = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = copy;
		}
	}
}
