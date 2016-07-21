/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:54:16 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 11:22:01 by daviwel          ###   ########.fr       */
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
	int		i;

	ant_crawl = ants;
	i = 0;
	while (ant_crawl != NULL)
	{
		temp_ant = (t_ant *)ant_crawl->data;
		if (move_ant(temp_ant, end) == 1)
			end->num_ants++;
		ant_crawl = ant_crawl->next;
		i++;
	}
}
