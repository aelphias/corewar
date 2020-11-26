/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:14:31 by marvin            #+#    #+#             */
/*   Updated: 2020/11/26 23:14:31 by marvin           ###   ########.fr       */
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
		free_all(*champ, "Error: wrong input\n");
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
			free_all(*champ, "Error: no name or comment\n");
		}
		free(line);
	}
}

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

void	is_body_valid(int fd, t_crw *champ)
{
	int		ans;
	char	*line;

	while ((ans = get_next_line(fd, &line)) > 0)
	{
		if (is_comment(line))
			;
		else if (is_command(line, champ))
			;
		else if (is_label_or_not(line, champ))
			;
		else
		{
			free_all(*champ, "Error: invalid file\n");
		}
		is_end_comment(champ, line);
		free(line);
	}
	finish_fill_label_range(champ);
}

void	is_file_valid(char *name, t_crw *champ)
{
	int		len;
	int		fd;
	char	buff;

	len = ft_strlen(name);
	fd = 0;
	if (len > 2 && name[len - 2] == '.' && name[len - 1] == 's' &&
	(fd = open(name, O_RDONLY)))
	{
		is_header_valid(fd, champ);
		is_body_valid(fd, champ);
	}
	else
		free_all(*champ, "Error: invalid file\n");
	close(fd);
	if (!(fd = open(name, O_RDONLY)))
		free_all(*champ, "Error: invalid file\n");
	lseek(fd, -1L, 2);
	read(fd, &buff, 1);
	if (buff != '\n' && !champ->is_end_comment)
		free_all(*champ, "Error: not found file or no new line at the end\n");
	close(fd);
}
