/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denis <denis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:12:17 by gjigglyp          #+#    #+#             */
/*   Updated: 2020/07/20 22:16:53 by denis            ###   ########.fr       */
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
