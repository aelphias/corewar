/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:37:53 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/11 19:37:53 by gjigglyp         ###   ########.fr       */
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
