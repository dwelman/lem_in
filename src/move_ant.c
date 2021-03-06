/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 14:04:55 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 09:42:03 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This function moves an ant and prints its number and what room it moves to,
** it also returns 1 if the ant should be removed
*/

int	move_ant(t_ant *ant, t_node *end)
{
	t_node	*temp;

	if (ant->has_moved == 0 && ant->at_end == 0)
	{
		ant->has_moved = 1;
		if (ant->crawl != NULL)
		{
			temp = (t_node *)ant->crawl->data;
			temp->has_ant = 0;
		}
		if (ant->crawl->next != NULL)
			ant->crawl = ant->crawl->next;
		temp = (t_node *)ant->crawl->data;
		ft_printf("L%d-%s ", ant->number, (char *)temp->name);
		if (ft_strcmp((char *)temp->name, (char *)end->name) == 0)
		{
			ant->at_end = 1;
			return (1);
		}
		temp->has_ant = 1;
	}
	return (0);
}
