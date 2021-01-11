/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:59:25 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/10 17:26:53 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	is_end_comment(t_crw *champ, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '#' || line[i] == '\0')
		champ->is_end_comment = 1;
	else
		champ->is_end_comment = 0;
}

void	is_file_valid_or_not(char *name, t_crw *champ)
{
	int		len;
	int		fd;
	char	buff;

	len = ft_strlen(name);
	fd = 0;
	if (len > 2 && name[len - 2] == '.' && name[len - 1] == 's' \
		&& (fd = open(name, O_RDONLY)))
		are_h_and_b_valid(fd, champ);
	else
		free_and_call(*champ, ER_IN_F);
	close(fd);
	if (!(fd = open(name, O_RDONLY)))
		free_and_call(*champ, ER_IN_F);
	lseek(fd, -1L, 2);
	read(fd, &buff, 1);
	if (buff != '\n' && !champ->is_end_comment)
		free_and_call(*champ, ERR_FNL);
	close(fd);
}
