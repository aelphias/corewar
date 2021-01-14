/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_are_h_and_b_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 12:01:49 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 18:20:29 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** проверка на случаи head и comment
*/

void	check_hdr_cases(char **line, t_crw *ch, int *name, int *mc)
{
	if (is_comment_or_not(*line))
		;
	else if (is_name(line, ch->fd, ch, *name))
		*name = 1;
	else if (is_main_cmnt_or_not(line, ch->fd, ch, *mc))
		*mc = 1;
	else
	{
		free(*line);
		free_and_call(*ch, ER_ININ);
	}
}

/*
** проверка на валидность хедера
*/

void	is_hdr_valid_or_not(int fd, t_crw *ch)
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
		check_hdr_cases(&line, ch, &name, &mc);
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

/*
** проверка на валидность того, что должно быть под именем и комментарием
*/

void	is_body_valid_or_not(int fd, t_crw *ch)
{
	int		ans;
	char	*line;

	while ((ans = get_next_line(fd, &line)) > 0)
	{
		if (is_comment_or_not(line))
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

/*
** проверяем всё вместе на валидность
*/

void	are_h_and_b_valid_or_not(int fd, t_crw *ch)
{
	is_hdr_valid_or_not(fd, ch);
	is_body_valid_or_not(fd, ch);
}
