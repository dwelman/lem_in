/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:54:16 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/19 07:59:59 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This function resets all the ants, allowing them to move
*/

void	reset_ants(t_list *ants)
{
	t_list	*ant_crawl;
	t_ant	*temp_ant;

	ant_crawl = ants;
	while (ant_crawl != NULL)
	{
		temp_ant = (t_ant *)ant_crawl->data;
		temp_ant->has_moved = 0;
		ant_crawl = ant_crawl->next;
	}
}
