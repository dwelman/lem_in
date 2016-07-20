/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:41:45 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/20 14:41:48 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_node(t_node *node)
{
	if (node->name != NULL)
		free(node->name);
	if (node->links != NULL)
		free(node->links);
	free(node);
}
