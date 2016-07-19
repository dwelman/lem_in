/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:26:21 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/19 08:12:13 by daviwel          ###   ########.fr       */
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
	int		cur_ant;

	cur_ant = 1;
	while (info->end->num_ants != info->num_ants)
	{
		path_crawl = info->paths;
		reset_ants(info->ants);
	}	
}
