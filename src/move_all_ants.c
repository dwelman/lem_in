/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:54:16 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/19 08:58:48 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This function loops through all the ants and makes them move on their paths
*/

void	move_all_ants(t_list *ants, t_node *end)
{
	t_list	*ant_crawl;
	t_ant	*temp_ant;

	ant_crawl = ants;
	while (ant_crawl != NULL)
	{
		temp_ant = (t_ant *)ant_crawl->data;
		move_ant(temp_ant, end);
		ant_crawl = ant_crawl->next;
	}
}
