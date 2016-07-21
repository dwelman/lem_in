/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:26:21 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 13:45:59 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This function is the control centre for all the ants. The loop runs until all
** the ants are in the end room, and it creates new ants and gives them the path
** they will follow
*/

void	spawn_ants(t_control *c, t_info *info)
{
	while (c->path_crawl != NULL)
	{
		c->cur_len = count_path(c->path_crawl);
		c->temp_path = (t_list *)c->path_crawl->data;
		c->temp_node = (t_node *)c->temp_path->next->data;
		if (c->cur_len == c->prev_len
			|| c->cur_len - c->prev_len < info->num_ants - c->cur_ant)
		{
			if (c->temp_node->has_ant == 0 && c->cur_ant <= info->num_ants)
			{
				ft_lstappend(&info->ants, ft_lstnew((void *)make_ant(c->cur_ant,
								c->temp_path)));
				c->cur_ant++;
			}
		}
		c->prev_len = count_path(c->path_crawl);
		c->path_crawl = c->path_crawl->next;
	}
}

void	control_ants(t_info *info)
{
	t_control	c;

	c.cur_ant = 1;
	while (info->end->num_ants < info->num_ants)
	{
		c.path_crawl = info->paths;
		c.prev_len = count_path(c.path_crawl);
		reset_ants(info->ants);
		move_all_ants(info->ants, info->end);
		spawn_ants(&c, info);
		move_all_ants(info->ants, info->end);
		ft_printf("\n");
	}
}
