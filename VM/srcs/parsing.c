/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:10 by aelphias          #+#    #+#             */
/*   Updated: 2020/12/24 19:21:40 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

void read_file(int fd, char *name, t_plr *plr)
{
	unsigned char buff[2];
	int i;
	int j;
	int l;

	l = 0;
	j = 0;
	i = 0;
	while (read(fd, buff, 1) > 0)
	{
		if (i >= 4 && i <= 132)
			plr->name[j++] = buff[0];
		if (i >= 140 && i <= 2186)
			plr->cmnt[l++] = buff[0];
		i++;
	}
	plr->name[j] = '\0';
	plr->cmnt[l] = '\0';
	close(fd);
}

void create_list_plr(t_plr *head, char *argv, int val, int fd)
{
    t_plr * current = head;

    while (current->next != NULL)
        current = current->next;
	if (!(current->next = (void*)ft_memalloc(sizeof(t_plr))))
 		print_error(ERR_MALLOC);
    current->next->id = val;
	current->next->name = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (PROG_NAME_LENGTH + 1));
	current->next->cmnt = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (COMMENT_LENGTH + 1));
	read_file(fd, argv, current->next);
    current->next->next = NULL;
}

void print_list(t_plr *plr) 
{
    while (plr != NULL) 
	{
        printf("%d\n", plr->id);
		ft_putstr(plr->name);
		ft_printf("\n");
		ft_putstr(plr->cmnt);
		ft_printf("\n");
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

void	ft_parse(int argc, char **argv, t_flg *flg)
{
	int i;
	int j;
	int fd;
	t_plr *plr;

	fd = 0;
	i = 1;
	j = 1;
	while (i <= argc)
	{
		if (checkdotcor(argv[i]))
		{
			
			if (j == 1)
			{
				fd = open(argv[i], O_RDONLY);
				if (!(plr = (void*)ft_memalloc(sizeof(t_plr))))
					print_error(ERR_MALLOC);
				plr->id = 1;
				plr->name = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (PROG_NAME_LENGTH + 1));
				plr->cmnt = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (COMMENT_LENGTH + 1));
				read_file(fd, argv[i], plr);
			}
			if (j > 1)
			{
				fd = open(argv[i], O_RDONLY);
				create_list_plr(plr, argv[i], j, fd);
			}
			j++;
		}
		i++;
	}
	print_list(plr);
	//check_flags(argc, argv, flg, plr);
	
	//check_filename(argc, argv);
	/*
	*checking filename and magic header
	*/
	//MAX_PLAYERS < argc ? print_error(ERR_M_PLRS) : 0; //check .cor implicitely 
}