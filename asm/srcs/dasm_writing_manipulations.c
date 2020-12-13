/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_writing_manipulations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:59:04 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/12/13 14:59:04 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		write_head_elem(char *elem, int cons, int wr_fd, int rd_fd)
{
	char	c;
	int		i;

	write(wr_fd, elem, ft_strlen(elem));
	i = 0;
	read(rd_fd, &c, 1);
	while (c != '\0' && i++ < cons)
	{
		write(wr_fd, &c, 1);
		read(rd_fd, &c, 1);
	}
	write(wr_fd, "\"\n", 2);
	while (i++ < cons)
		read(rd_fd, &c, 1);
}

void		read_value(t_dasm *dis, int rd_fd)
{
	dis->value = dis->value << 8;
	read(rd_fd, &dis->c, 1);
	dis->value = dis->value | dis->c;
}

void		read_first_value(t_dasm *dis, int rd_fd)
{
	read(rd_fd, &dis->c, 1);
	dis->value = dis->c;
}

void		write_label(int *output, t_dasm *dis, int rd_fd, int wr_fd)
{
	char	p;

	p = DIRECT_CHAR;
	write(wr_fd, "%", 1);
	if (dis->dir_size == 2)
	{
		read_first_value(dis, rd_fd);
		read_value(dis, rd_fd);
		*output = (int16_t)dis->value;
	}
	else if (dis->dir_size == 4)
	{
		read_first_value(dis, rd_fd);
		read_value(dis, rd_fd);
		read_value(dis, rd_fd);
		read_value(dis, rd_fd);
		*output = dis->value;
	}
}

void		write_arg(int wr_fd, t_dasm *dis, int rd_fd, int arg)
{
	char	*to_wr;
	int		output;

	dis->value = 0;
	output = 0;
	if (arg == 1)
	{
		write(wr_fd, "r", 1);
		read(rd_fd, &dis->c, 1);
		output = dis->c;
	}
	else if (arg == 2)
		write_label(&output, dis, rd_fd, wr_fd);
	else if (arg == 3)
	{
		read_first_value(dis, rd_fd);
		read_value(dis, rd_fd);
		output = (int16_t)dis->value;
	}
	to_wr = ft_itoa_1(output);
	write(wr_fd, to_wr, ft_strlen(to_wr));
	free(to_wr);
}
