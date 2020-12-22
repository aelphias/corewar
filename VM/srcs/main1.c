/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:47:00 by sdarron           #+#    #+#             */
/*   Updated: 2020/12/22 16:58:38 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define MEM_SIZE (4*1024)


typedef struct			s_pc
{
	int					carry;
	unsigned int		parent;
	unsigned int		reg[16];
	int					live;
	int					command;
	int					cicles;
	int					left_live;
	int					size;
	unsigned int		arg[3];
	int					aff;
	int					id;
	struct s_pc			*next;
	int					change;
}						t_pc;

typedef struct			s_rule
{
	int					aff;
	int					visual;
	unsigned int		dump;
	int					i;
	int					c;
	int					j;
	int					check_dump;
	int					id;
}						t_rule;

typedef struct			s_player
{
	unsigned char		*p_name;
	unsigned char		*p_comment;
	unsigned int		*p_code;
	unsigned int		p_id;
	int					p_size;
	int					p_live;
	int					stand;
	int					pc_id;
	struct s_player		*next;
	unsigned int		last_live;
	int					i;
}						t_player;


void	init_pc(t_pc **tmp, unsigned int parent, int stand, t_rule *r)
{
	int i;
	t_pc *pc;
	
	i = 0;
	pc = (t_pc*)malloc(sizeof(t_pc));
	while (i++ < 16)
		pc->reg[i] = 0;
	i = -1;
	while (++i < 3)
		pc->arg[i] = 0;
	pc->reg[0] = parent;
	pc->change = -1;
	pc->left_live = 0;
	if ((r->aff) == 1)
		pc->aff = 1;
	else
		pc->aff = 0;
	pc->carry = 0;
	pc->live = 1;
	pc->id = r->id++;
	pc->parent = parent;
	pc->cicles = 0;
	pc->command = 0;
	pc->size = stand;
	pc->next = NULL;
	if ((*tmp) == NULL) //  ?????
		*tmp = pc;
	else
	{
		pc->next = (*tmp);
		*tmp = pc;
	}
}
	

int count_playr(t_player *p)
{
	int i;
	
	i = 0;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}
	return (i);
}

t_pc *new_pc(t_player *p, t_rule *r)
{
	int i;
	int j;
	int del;
	t_pc *pc;

	pc = NULL;
	j = -1;
	i = count_playr(p);
	if (i % 2 == 0)
		del = 4096;
	else
		del = 4095;
	if (i == 0 || i > 4)
		return (NULL);
	while (++j < i)
	{
		p->stand = (j * (del / i));
		init_pc(&pc, p->p_id, ((j * (del / i))), r);
		p->next;
	}
	return(pc);
}


int main()
{
	t_rule *rule;
	t_player *p;
	t_pc *pc;
	unsigned char	map[MEM_SIZE];
	int i;
	i = 0;
	
	while (++i < MEM_SIZE)
		map[i] = 0;
	pc = new_pc(p, rule);




	return (0);
}
