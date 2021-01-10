/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_are_h_and_b_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:01:49 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/26 13:03:26 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	header_cases(char **line, t_crw *champ, int *name, int *mc)
{
	if (is_comment(*line))
		;
	else if (is_name(line, champ->fd, champ, *name))
		*name = 1;
	else if (is_main_comment(line, champ->fd, champ, *mc))
		*mc = 1;
	else
	{
		free(*line);
		free_all(*champ);
		call_error(ER_ININ);
	}
}

void	is_header_valid(int fd, t_crw *champ)
{
	int		name;
	int		mc;
	char	*line;
	int		ans;

	name = 0;
	mc = 0;
	champ->fd = fd;
	while ((ans = get_next_line(fd, &line)) > 0)
	{
		header_cases(&line, champ, &name, &mc);
		if (name == 1 && mc == 1)
		{
			free(line);
			break ;
		}
		if (is_command_or_not(line, champ))
		{
			free(line);
			free_all(*champ);
			call_error(NO_N_CO);
		}
		free(line);
	}
}

void	is_body_valid(int fd, t_crw *champ)
{
	int		ans;
	char	*line;

	while ((ans = get_next_line(fd, &line)) > 0)
	{
		if (is_comment(line))
			;
		else if (is_command_or_not(line, champ))
			;
		else if (is_label_or_not(line, champ))
			;
		else
		{
			free_all(*champ);
			call_error(ER_IN_F);
		}
		is_end_comment(champ, line);
		free(line);
	}
	finish_fill_label_range(champ);
}

void	are_h_and_b_valid(int fd, t_crw *champ)
{
	is_header_valid(fd, champ);
	is_body_valid(fd, champ);
}
