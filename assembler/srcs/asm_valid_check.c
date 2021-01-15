/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:59:25 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/15 14:52:35 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	is_end_comment_or_not(t_crw *ch, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '#' || line[i] == '\0')
		ch->is_ec = 1;
	else
		ch->is_ec = 0;
}

void	is_file_valid_or_not(char *name, t_crw *ch)
{
	int		len;
	int		fd;
	char	buf;

	len = ft_strlen(name);
	fd = 0;
	if (len > 2 && name[len - 2] == '.' && name[len - 1] == 's' \
		&& (fd = open(name, O_RDONLY)))
		are_h_and_b_valid_or_not(fd, ch);
	else
		free_and_call(*ch, ER_IN_F);
	close(fd);
	if (!(fd = open(name, O_RDONLY)))
		free_and_call(*ch, ER_IN_F);
	lseek(fd, -1L, 2);
	read(fd, &buf, 1);
	if (buf != '\n' && !ch->is_ec)
		free_and_call(*ch, ERR_FNL);
	close(fd);
}
