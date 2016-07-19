/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:26:21 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/19 11:12:55 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This function is the control centre for all the ants. The loop runs until all
** the ants are in the end room, and it creates new ants and gives them the path
** they will follow
*/

void	control_ants(t_info *info)
{
	t_list	*path_crawl;
	t_list	*temp_path;
	t_node	*temp_node;
	int		cur_ant;

	cur_ant = 1;
	while (info->end->num_ants != info->num_ants)
	{
		path_crawl = info->paths;
		reset_ants(info->ants);
		move_all_ants(info->ants, info->end);
		while (path_crawl != NULL)
		{
			temp_path = (t_list *)path_crawl->data;
			temp_node = (t_node *)temp_path->next->data;
			if (temp_node->has_ant == 0)
			{
				ft_lstappend(&info->ants, ft_lstnew((void *)make_ant(cur_ant,
								temp_path)));
				cur_ant++;
			}
			path_crawl = path_crawl->next;
		}
		ft_printf("HAI\n");
		move_all_ants(info->ants, info->end);
	}
}
