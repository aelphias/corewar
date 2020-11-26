/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:08:21 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/07/20 22:10:13 by denis            ###   ########.fr       */
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
