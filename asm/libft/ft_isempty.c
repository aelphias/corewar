/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:16:28 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/09/05 19:16:28 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isempty(char *line)
{
	int i;

	i = 0;
	if (!line || line[i] == '\0')
		return (0);
	while (line[i])
	{
		if (ft_isgraph(line[i]))
			return (1);
		i++;
	}
	return (0);
}
