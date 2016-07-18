/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 09:55:33 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/18 13:14:35 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Finds a node with a certain name
*/

t_node	*find_node(t_info *info, char *name)
{
	int	i;

	i = 0;
	while (i < info->num_rooms)
	{
		if (ft_strcmp(name, (char *)info->nodes[i]->name) == 0)
			return (info->nodes[i]);
		i++;
	}
	error();
	return (NULL);
}

/*
** Replaces the names in the paths with actual nodes to make traversal easier
*/

void	replace_nodes(t_info *info)
{
	t_list	*crawl;
	t_list	*trav;
	char	*temp;

	crawl = info->paths;
	while (crawl != NULL)
	{
		trav = (t_list *)crawl->data;
		while (trav != NULL)
		{
			temp = (char *)trav->data;
			if (trav->data != NULL)
				free((char *)trav->data);
			trav->data = (void *)find_node(info, (char *)trav->data);
			trav = trav->next;
		}
		crawl = crawl->next;
	}
}
