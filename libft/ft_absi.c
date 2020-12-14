/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:07:44 by gjigglyp          #+#    #+#             */
/*   Updated: 2019/10/24 19:12:37 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_absi(int n)
{
	unsigned int	dst;

	if (n < 0)
		dst = (unsigned int)(-n);
	else
		dst = (unsigned int)n;
	return (dst);
}
