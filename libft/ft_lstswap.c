/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:26:03 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/21 17:26:03 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstswap(t_list *lst1, t_list *lst2)
{
	lst1->next = lst2->next;
	lst2->next = lst1;
	return (lst2);
}
