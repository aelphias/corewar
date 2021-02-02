/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:27:42 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/09/05 19:14:44 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, char control)
{
	char	*mem;

	mem = ft_strjoin(s1, s2);
	if (control == 'L' || control == 'B')
		free(s1);
	if (control == 'R' || control == 'B')
		free(s2);
	return (mem);
}
