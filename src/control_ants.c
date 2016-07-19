/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:26:21 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/19 07:58:24 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	control_ants(t_info *info)
{
	t_list	*path_crawl;
	t_list	*ant_crawl;
	t_ant	*temp_ant;
	int		cur_ant;

	cur_ant = 1;
	while (info->end->num_ants != info->num_ants)
	{
		path_crawl = info->paths;
		ant_crawl = info->ants;
		while (ant_crawl != NULL)
		{
			temp_ant = (t_ant *)ant_crawl->data;
			temp_ant->has_moved = 0;
			ant_crawl = ant_crawl->next;
		}
	}	
}
