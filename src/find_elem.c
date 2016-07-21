/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 14:53:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 13:31:30 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Finds a specific element in the array of nodes
*/

int	find_elem(t_node **nodes, char *name, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (ft_strcmp(name, nodes[i]->name) == 0)
			return (i);
		i++;
	}
	return (-1);
}
