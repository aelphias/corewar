/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:40:54 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 16:48:00 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_no_name(char **line, t_crw *ch)
{
	free(*line);
	free_and_call(*ch, NO_NAME);
}

void	if_prog_length(t_crw *ch, char **line)
{
	free(*line);
	free_and_call(*ch, LONG_NA);
}
