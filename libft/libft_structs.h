/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:36:04 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/14 13:36:04 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTS_H
# define LIBFT_STRUCTS_H
# include <string.h>

typedef struct				s_tree
{
	void					*content;
	size_t					content_size;
	struct s_tree			*left;
	struct s_tree			*right;

}							t_tree;

typedef struct				s_forward_list
{	void					*content;
	size_t					content_size;
	struct s_forward_list	*next;
}							t_forward_list;

typedef struct				s_list_a
{	void					*content;
	size_t					content_size;
	struct s_list_a			*next;
	struct s_list_a			*prev;
}							t_list_a;

typedef struct				s_flist
{
	int						fd;
	char					*content;
	struct s_flist			*next;
}							t_flist;

#endif
