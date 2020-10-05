/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qweissna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:24:36 by qweissna          #+#    #+#             */
/*   Updated: 2018/12/24 21:46:39 by qweissna         ###   ########.fr       */
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
