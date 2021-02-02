/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:14:13 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/11/21 17:14:13 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubblesort_array(char **tab, size_t n)
{
	int		sorted;
	size_t	i;
	char	*s;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < n - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				s = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = s;
				sorted = 0;
			}
			i++;
		}
	}
}
