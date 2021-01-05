/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:13:10 by aelphias          #+#    #+#             */
/*   Updated: 2021/01/05 16:42:32 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"

void error_magic_numb()
{
	//free
	write(2, "ERROR CHAMP MAGIC NUMBER\n", 25);
	exit(1);
}

void error_camp_max_size()
{
	//free
	write(2, "ERROR CHAMP MAX SIZE\n", 21);
	exit(1);
}

void read_file(int fd, char *name, t_plr *plr)
{
	unsigned char buff[2];
	int i;
	int j;
	int l;
	int k;
	int c;
	int m;
	unsigned char sizecode[4] = {0};
	unsigned char magicnum[4] = {0};

	k = 0;
	l = 0;
	j = 0;
	i = 0;
	c = 0;
	m = 0;
	while (read(fd, buff, 1) > 0)
	{
		if (i >= 0 && i <=3)
			magicnum[m++] = (unsigned int)buff[0];
		if (i >= 4 && i <= 132)
			plr->name[j++] = (unsigned char)buff[0];
		if (i >= 140 && i <= 2186)
			plr->cmnt[l++] = (unsigned char)buff[0];
		if (i >= 2192 && i <= 2874)
			plr->code[k++] = (unsigned int)buff[0];
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
	if (plr->codesize > CHAMP_MAX_SIZE)
		error_camp_max_size();
	if (!((magicnum[0] == 00) && (magicnum[1] == 234) && (magicnum[2] == 131) && (magicnum[3] == 243)))
		error_magic_numb();
	//plr->name[j] = '\0';
	//plr->cmnt[l] = '\0';
	close(fd);
}

void create_list_plr(t_plr *head, char *argv, int val, int fd)
{
	t_plr *current = head;

	while (current->next != NULL)
		current = current->next;
	if (!(current->next = (void*)ft_memalloc(sizeof(t_plr))))
 		print_error(ERR_MALLOC);
	current->next->id = val;
	current->next->name = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (PROG_NAME_LENGTH + 1));
	current->next->cmnt = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (COMMENT_LENGTH + 1));
	current->next->code = (unsigned int *)ft_memalloc(sizeof(unsigned int) * CHAMP_MAX_SIZE);
	ft_bzero(current->next->code, 0);
	read_file(fd, argv, current->next);
	current->next->next = NULL;
}

int checkdotcor(char *argv)
{
	int len;

	len = 0;
	len = ft_strlen(argv);
	if (len < 5)
	{
		//free();
		write(2, "ERROR FILE CHAMP\n", 17);
		exit(1);
	}
	if (argv[len - 1] == 'r' && argv[len - 2] == 'o' && argv[len - 3] ==  'c' && argv[len - 4] == '.')
		return (1);
	else
		return (0);
}
/*
* revlist Subject: Yes, the last born (youngest) champion plays first.
*/

t_plr *revlist(t_plr *plr)
{
	t_plr *prev = NULL;
	while (plr)
	{
		t_plr *next = plr->next;
		plr->next = prev;
		prev = plr;
		plr = next;
	}
	return (prev);
}

void error_file()
{
	//free();
	write(2, "ERROR FILE CHAMP\n", 17);
	exit(1);
}

/*
* разбить  ft_parse на ф_ции
*/

t_plr *add_one_plr(char **argv, t_plr *plr, int i, int j)
{
	int fd;
	
	fd = 0;
	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
	{
		//free();
		write(2, "ERROR FILE CHAMP\n", 17);
		exit(1);
	}
	if (!(plr = (void*)ft_memalloc(sizeof(t_plr))))
		print_error(ERR_MALLOC);
	plr->id = j;
	plr->name = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (PROG_NAME_LENGTH + 1));
	plr->cmnt = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (COMMENT_LENGTH + 1));
	plr->code = (unsigned int *)ft_memalloc(sizeof(unsigned int) * CHAMP_MAX_SIZE);
	ft_bzero(plr->code, 0);
	read_file(fd, argv[i], plr);
	close(fd);
	return (plr);
}

t_plr	 *ft_parse(int argc, char **argv, t_vm *vm)
{
	int i;
	int id;
	int fd;
	t_plr *plr;

	i = 1;
	id = -1;
	while (i <= argc)
	{
		if ((ft_strcmp(argv[i], "-dump")) == 0)
		{
			if (argc <= 2)
				print_error(ERR_USE);
			if (i + 1 == argc)
				break ;
			else
				i = i + 2;
		}
		if (checkdotcor(argv[i]))
		{
			if (id == -1)
				plr = add_one_plr(argv, plr, i, id);
			if (id < -1)
			{
				fd = open(argv[i], O_RDONLY);
				if (fd == -1)
					error_file();
				create_list_plr(plr, argv[i], id, fd);
				//plr->id = id;
				close(fd);
			}
			id--;
		}
		else
			error_file();
		i++;
	}


/* 	while(plr)
	{
		ft_printf("PLR %d \n", plr->id);
		plr = plr->next;	
	} */
	//plr = revlist(plr); // Subject, p.16:  Yes, the last born (youngest) champion plays first.
	return (plr);
}
