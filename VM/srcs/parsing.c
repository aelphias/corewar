/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:11:46 by marvin            #+#    #+#             */
/*   Updated: 2021/01/30 10:34:27 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		read_file(int fd, t_plr *plr, int i)
{
	uint8_t	buff[2];
	uint8_t	sizecode[4];
	uint8_t	magicnum[4];
	t_count *count;

	if (!(count = (t_count *)ft_memalloc(sizeof(t_count))))
		print_error(ERR_MALLOC);
	ft_bzero(count, 0);
	while (read(fd, buff, 1) > 0)
	{
		if (i >= 0 && i <= 3)
			magicnum[count->m++] = (uint8_t)buff[0];
		if (i >= 136 && i <= 139)
			sizecode[count->c++] = (uint8_t)buff[0];
		if (i >= 4 && i <= 132)
			plr->name[count->j++] = (uint8_t)buff[0];
		if (i >= 140 && i <= 2186)
			plr->cmnt[count->l++] = (uint8_t)buff[0];
		if (i >= 2192 && i <= 2874 && count->k <= MEM_SIZE / 6)
			plr->code[count->k++] = (uint8_t)buff[0];
		i++;
	}
	get_sizecode(plr, sizecode);
	check_max_size_and_magicnum(plr, magicnum, fd);
	free(count);
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
	plr->code = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (CHAMP_MAX_SIZE + 1));
	plr->head = plr;
	ft_bzero(plr->code, 0);
	read_file(fd, plr, 0);
	close(fd);
	return (plr);
}

int			get_error_for_n(int i, int argc, char **argv)
{
	if (i >= argc - 1)
		print_error(ERR_USE);
	else if (!(is_num(argv[i + 1])))
		print_error(ERR_USE);
	else
		i = i + 2;
	return (i);
}

t_plr		*ft_parse(int argc, char **argv, int i, int id)
{
	t_plr	*plr;

	while (++i <= argc)
	{
		if ((ft_strcmp(argv[i], "-dump")) == 0)
		{
			if (i + 1 == argc)
				break ;
			else
				i = i + 2;
		}
		if ((ft_strcmp(argv[i], "-n")) == 0)
			i = get_error_for_n(i, argc, argv);
		if (checkdotcor(argv[i]))
		{
			if (id == 1)
				plr = add_one_plr(argv, plr, i, id);
			if (id > 1)
				gat_list_plrs(argv, id, plr, i);
			id++;
		}
		else
			error_file();
	}
	return (plr);
}
