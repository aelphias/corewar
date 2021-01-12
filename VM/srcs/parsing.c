/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:11:46 by marvin            #+#    #+#             */
/*   Updated: 2021/01/12 21:22:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		check_max_size_and_magicnum(t_plr *plr, uint8_t *magicnum, int fd)
{
	if (plr->codesize > CHAMP_MAX_SIZE)
		error_champ_max_size();
	if (!((magicnum[0] == 00) && (magicnum[1] == 234) && (magicnum[2] == 131)
		&& (magicnum[3] == 243)))
		error_magic_numb();
	close(fd);
}

void		get_sizecode(t_plr *plr, uint8_t *sizecode)
{
	int		i;
	int		j;

	i = 4;
	j = 0;
	while (--i >= 0)
	{
		plr->codesize += sizecode[j];
		plr->codesize = plr->codesize << (i * 8);
		j++;
	}
}

void		write_name_cmnt_code_in_plr(int i, t_plr *plr, uint8_t *buff)
{
	int		j;
	int		l;
	int		k;

	j = 0;
	l = 0;
	k = 0;
	if (i >= 4 && i <= 132)
		plr->name[j++] = (uint8_t)buff[0];
	if (i >= 140 && i <= 2186)
		plr->cmnt[l++] = (uint8_t)buff[0];
	if (i >= 2192 && i <= 2874)
		plr->code[k++] = (uint8_t)buff[0];
}

void		read_file(int fd, t_plr *plr, int i)
{
	uint8_t	buff[2];
	int		c;
	int		m;
	uint8_t	sizecode[4];
	uint8_t	magicnum[4];

	i = 0;
	c = 0;
	m = 0;
	while (read(fd, buff, 1) > 0)
	{
		if (i >= 0 && i <= 3)
			magicnum[m++] = (uint8_t)buff[0];
		if (i >= 136 && i <= 139)
			sizecode[c++] = (uint8_t)buff[0];
		write_name_cmnt_code_in_plr(i, plr, buff);
		i++;
	}
	get_sizecode(plr, sizecode);
	check_max_size_and_magicnum(plr, magicnum, fd);
}

void		create_list_plr(t_plr *head, int val, int fd)
{
	t_plr *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	if (!(current->next = (void*)ft_memalloc(sizeof(t_plr))))
		print_error(ERR_MALLOC);
	current->next->id = val;
	current->next->name = (uint8_t *)ft_memalloc(sizeof(uint8_t)
		* (PROG_NAME_LENGTH + 1));
	current->next->cmnt = (uint8_t *)ft_memalloc(sizeof(uint8_t)
		* (COMMENT_LENGTH + 1));
	current->next->code = (uint8_t *)ft_memalloc(sizeof(uint8_t)
		* CHAMP_MAX_SIZE);
	ft_bzero(current->next->code, 0);
	read_file(fd, current->next, 0);
	current->next->next = NULL;
}

int			checkdotcor(char *argv)
{
	int		len;

	len = 0;
	len = ft_strlen(argv);
	if (argv[len - 1] == 'r' && argv[len - 2] == 'o' && argv[len - 3] == 'c' &&
		argv[len - 4] == '.')
		return (1);
	else
		return (0);
}

t_plr		*revlist(t_plr *plr)
{
	t_plr	*prev;
	t_plr	*next;

	prev = NULL;
	while (plr)
	{
		next = plr->next;
		plr->next = prev;
		prev = plr;
		plr = next;
	}
	return (prev);
}

t_plr		*add_one_plr(char **argv, t_plr *plr, int i, int j)
{
	int		fd;

	fd = 0;
	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
		error_file();
	if (!(plr = (void*)ft_memalloc(sizeof(t_plr))))
		print_error(ERR_MALLOC);
	plr->id = j;
	plr->name = (uint8_t *)ft_memalloc(sizeof(uint8_t) *
		(PROG_NAME_LENGTH + 1));
	plr->cmnt = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (COMMENT_LENGTH + 1));
	plr->code = (uint8_t *)ft_memalloc(sizeof(uint8_t) * CHAMP_MAX_SIZE);
	ft_bzero(plr->code, 0);
	read_file(fd, plr, 0);
	close(fd);
	return (plr);
}

t_plr		*ft_parse(int argc, char **argv)
{
	int		i;
	int		id;
	int		fd;
	t_plr	*plr;

	i = 1;
	id = 1;
	while (i <= argc)
	{
		if ((ft_strcmp(argv[i], "-dump")) == 0)
		{
			if (i + 1 == argc)
				break ;
			else
				i = i + 2;
		}
		if ((ft_strcmp(argv[i], "-n")) == 0)
		{
			if (i >= argc - 1)
				print_error(ERR_USE);
			else if (!(is_num(argv[i + 1])))
				print_error(ERR_USE);
			else
				i = i + 2;
		}
		if (checkdotcor(argv[i]))
		{
			if (id == 1)
				plr = add_one_plr(argv, plr, i, id);
			if (id > 1)
			{
				fd = open(argv[i], O_RDONLY);
				if (fd == -1)
					error_file();
				create_list_plr(plr, id, fd);
				close(fd);
			}
			id++;
		}
		else
			error_file();
		i++;
	}
	return (plr);
}
