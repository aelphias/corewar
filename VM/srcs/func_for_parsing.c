/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:19:23 by sdarron           #+#    #+#             */
/*   Updated: 2021/01/13 14:19:54 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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

void		check_max_size_and_magicnum(t_plr *plr, uint8_t *magicnum, int fd)
{
	if (plr->codesize > CHAMP_MAX_SIZE)
		error_champ_max_size();
	if (!((magicnum[0] == 00) && (magicnum[1] == 234) && (magicnum[2] == 131)
		&& (magicnum[3] == 243)))
		error_magic_numb();
	close(fd);
}

void		gat_list_plrs(char **argv, int id, t_plr *plr, int i)
{
	int		fd;

	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
		error_file();
	if (id > 4)
		print_error(2);
	create_list_plr(plr, id, fd);
	close(fd);
}
