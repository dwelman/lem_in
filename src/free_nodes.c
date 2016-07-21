/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 15:12:46 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/20 15:31:34 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_nodes(t_node **nodes, int node_count)
{
	int	i;

	while (i < node_count)
	{
		free_node(nodes[i]);
		i++;
	}
	free(nodes);
}
