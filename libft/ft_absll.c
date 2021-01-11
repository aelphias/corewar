/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:21:47 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/11 19:21:50 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_absll(long long n)
{
	unsigned long long	dst;

	if (n < 0)
		dst = (unsigned long long)(-n);
	else
		dst = (unsigned long long)n;
	return (dst);
}
