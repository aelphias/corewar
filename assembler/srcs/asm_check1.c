/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjigglyp <gjigglyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:38:07 by gjigglyp          #+#    #+#             */
/*   Updated: 2021/01/25 15:29:57 by gjigglyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label_and_cmnd(t_crw *crw)
{
	char	*tmp_str;
	char	**arr_words;
	int		nb_words;

	if (ft_strlen(crw->string) == 0)
		return ;
	tmp_str = add_spaces(crw->string);
	arr_words = split_str(tmp_str);
	free_str_arr(&tmp_str, NULL, 1);
	nb_words = 0;
	while (arr_words[nb_words])
		nb_words++;
	if (is_label(arr_words[0]))
		check_label(crw, arr_words, nb_words);
	else if (is_cmnd(arr_words[0]) != 0)
		check_cmnd(crw, arr_words,
				is_cmnd(arr_words[0]), nb_words);
	else
		call_simple_error("ERROR: invalid string\n");
	free_str_arr(NULL, &arr_words, 0);
}

void		check_name(t_crw *crw)
{
	if ((ft_strncmp(&crw->af[crw->arp],
								NAME_CMD_STRING, 5)) == 0)
	{
		if (crw->if_name_exist == 1)
			call_simple_error("ERROR: the champ's name has occurred more than once\n");
		crw->arp += 5;
		spaceskip(crw);
		if (crw->af[crw->arp] == '\"')
		{
			if (crw->af[crw->arp + 1] == '\"')
			{
				crw->if_name_exist = 1;
				crw->arp += 2;
			}
			else
				fill_name(crw);
			checkfs(crw);
		}
		else
			call_simple_error("ERROR: wrong name of champion\n");
	}
	else
		call_simple_error("ERROR: wrong cmnd after '.'\n");
}

void		check_cmnt(t_crw *crw)
{
	if ((ft_strncmp(&crw->af[crw->arp],
							COMMENT_CMD_STRING, 8)) == 0)
	{
		if (crw->if_cmnt_exist == 1)
			call_simple_error("ERROR: the champion's comment has occurred more than once\n");
		crw->arp += 8;
		spaceskip(crw);
		if (crw->af[crw->arp] == '\"')
		{
			if (crw->af[crw->arp + 1] == '\"')
			{
				crw->if_cmnt_exist = 1;
				crw->arp += 2;
			}
			else
				fill_cmnt(crw);
			checkfs(crw);
		}
		else
			call_simple_error("ERROR: wrong comment of champion\n");
	}
	else
		call_simple_error("ERROR: wrong cmnd after '.'\n");
}