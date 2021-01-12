/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_are_h_and_b_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:01:49 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/05 13:36:33 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	header_cases(char **line, t_crw *ch, int *name, int *mc)
{
	if (is_comment(*line))
		;
	else if (is_name(line, ch->fd, ch, *name))
		*name = 1;
	else if (is_main_comment(line, ch->fd, ch, *mc))
		*mc = 1;
	else
	{
		free(*line);
		free_and_call(*ch, ER_ININ);
	}
}

void	is_header_valid(int fd, t_crw *ch)
{
	int		name;
	int		mc;
	char	*line;
	int		ans;

	name = 0;
	mc = 0;
	ch->fd = fd;
	while ((ans = get_next_line(fd, &line)) > 0)
	{
		header_cases(&line, ch, &name, &mc);
		if (name == 1 && mc == 1)
		{
			free(line);
			break ;
		}
		if (is_command_or_not(line, ch))
		{
			free(line);
			free_and_call(*ch, NO_N_CO);
		}
		free(line);
	}
}

void	is_body_valid(int fd, t_crw *ch)
{
	int		ans;
	char	*line;

	while ((ans = get_next_line(fd, &line)) > 0)
	{
		if (is_comment(line))
			;
		else if (is_command_or_not(line, ch))
			;
		else if (is_label_or_not(line, ch))
			;
		else
		{
			free_and_call(*ch, ER_IN_F);
		}
		is_end_comment(ch, line);
		free(line);
	}
	finish_fill_label_range(ch);
}

void	are_h_and_b_valid(int fd, t_crw *ch)
{
	is_header_valid(fd, ch);
	is_body_valid(fd, ch);
}
