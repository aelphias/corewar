/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:10 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/27 20:34:46 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

void read_file(int fd, int fd1, char *name, t_plr *plr)
{
	unsigned char buff[2];
	int i;
	int j;
	int l;
	int k;
	int c;
	unsigned int sizecode[4] = {0};

	k = 0;
	l = 0;
	j = 0;
	i = 0;
	c = 0;
	while (read(fd, buff, 1) > 0)
	{
		if (i >= 4 && i <= 132)
			plr->name[j++] = (unsigned char)buff[0];
		if (i >= 140 && i <= 2186)
			plr->cmnt[l++] = (unsigned char)buff[0];
		if (i >= 2192 && i <= 2874)
			plr->code[k++] = (int)buff[0];
		if (i >= 136 && i <= 139)
			sizecode[c++] = (unsigned int)buff[0];
		i++;
	}
	i = 4;
	j = 0;
	while (--i >= 0)
	{
		plr->codesize += sizecode[j];
		plr->codesize = plr->codesize << (i * 8);
		j++;
	}
	plr->name[j] = '\0';
	plr->cmnt[l] = '\0';
	close(fd);
}

void create_list_plr(t_plr *head, char *argv, int val, int fd, int fd1)
{
    t_plr * current = head;

    while (current->next != NULL)
        current = current->next;
	if (!(current->next = (void*)ft_memalloc(sizeof(t_plr))))
 		print_error(ERR_MALLOC);
    current->next->id = val;
	current->next->name = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (PROG_NAME_LENGTH + 1));
	current->next->cmnt = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (COMMENT_LENGTH + 1));
	current->next->code = (unsigned int *)ft_memalloc(sizeof(unsigned int) * CHAMP_MAX_SIZE);
	ft_bzero(current->next->code, 0);
	read_file(fd, fd1, argv, current->next);
    current->next->next = NULL;
}

void print_list(t_plr *plr) 
{
    while (plr != NULL) 
	{
        int i = 0;
		printf("%d\n", plr->id);
		ft_putstr(plr->name);
		ft_printf("\n");
		ft_putstr(plr->cmnt);
		ft_printf("\n");
		while (i < 50)
			ft_printf("%x ", plr->code[i++]);
		ft_printf("\n");
		ft_printf("%d\n", plr->codesize);
    	plr = plr->next;
	}
}

int checkdotcor(char *argv)
{
	int len;
	len = 0;

	len = ft_strlen(argv);
	if (argv[len - 1] == 'r' && argv[len - 2] == 'o' && argv[len - 3] ==  'c' && argv[len - 4] == '.')
		return (1);
	else
		return (0);
}

t_plr	 *ft_parse(int argc, char **argv, t_flg *flg)
{
	int i;
	int j;
	int fd;
	int fd1;
	t_plr *plr;

	fd = 0;
	i = 1;
	j = -1;
	while (i <= argc)
	{
		if (checkdotcor(argv[i]))
		{
			
			if (j == -1)
			{
				fd = open(argv[i], O_RDONLY);
				fd1 = open(argv[i], O_RDONLY);
				if (!(plr = (void*)ft_memalloc(sizeof(t_plr))))
					print_error(ERR_MALLOC);
				plr->id = -1;
				plr->name = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (PROG_NAME_LENGTH + 1));
				plr->cmnt = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (COMMENT_LENGTH + 1));
				plr->code = (unsigned int *)ft_memalloc(sizeof(unsigned int) * 862);
				ft_bzero(plr->code, 0);
				read_file(fd, fd1, argv[i], plr);
			}
			if (j < -1)
			{
				fd = open(argv[i], O_RDONLY);
				fd1 = open(argv[i], O_RDONLY);
				create_list_plr(plr, argv[i], j, fd, fd1);
			}
			j--;
		}
		i++;
	}
	print_list(plr);
	return (plr);
}
