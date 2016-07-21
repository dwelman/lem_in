/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:18:39 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 12:17:44 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Counts all the connections from the input
*/

int		count_connections(t_info *info, int j)
{
	int	i;

	i = 0;
	while (info->input[j])
	{
		if (*info->input[j] != '#')
			i++;
		j++;
	}
	return (i + 1);
}

/*
** Makes a link between 2 rooms based on the input given
*/

int		set_link(t_info *info, char *name, t_connect connect, int link)
{
	int		connections;
	int		temp_link;
	char	**temp;

	connections = count_connections(info, connect.j);
	temp_link = 0;
	temp = ft_strsplit(info->input[connect.i], '-');
	if (temp[0] == NULL || temp[1] == NULL)
		error();
	if (ft_strcmp(temp[0], name) == 0)
	{
		temp_link = find_elem(NODES, temp[1], connections);
		NODES[connect.k]->links[link] = NODES[temp_link];
		return (1);
	}
	else if (ft_strcmp(temp[1], name) == 0)
	{
		temp_link = find_elem(NODES, temp[0], connections);
		NODES[connect.k]->links[link] = NODES[temp_link];
		return (1);
	}
	else
		return (0);
}

/*
** Finds links between rooms and adds them to the array of links in each node
*/

void	make_links(t_info *info, char *name, int j, int k)
{
	int			link;
	t_connect	connect;
	char		*tmp;

	connect.i = j;
	connect.j = j;
	connect.k = k;
	link = 0;
	while (info->input[connect.i])
	{
		if (*info->input[connect.i] != '#')
			if ((tmp = ft_strstr(info->input[connect.i], name)) != NULL)
			{
				if (set_link(info, name, connect, link) == 1)
					link++;
			}
		connect.i++;
	}
}

/*
** Counts the number nodes that a room connects to
*/

int		count_nodes(t_info *info, char *name, int j)
{
	int	i;
	int	count;

	i = j;
	count = 0;
	while (info->input[i])
	{
		if (ft_strstr(info->input[i], name) != NULL && *info->input[i] != '#')
			count++;
		i++;
	}
	return (count);
}

/*
** Goes through the process of allocating memory and making connections between
** rooms
*/

void	connect_nodes(t_info *info, int *i)
{
	int	j;

	j = 0;
	while (j < info->num_rooms)
	{
		NODES[j]->num_links = count_nodes(info, NODES[j]->name, *i);
		NODES[j]->links = (t_node **)malloc(sizeof(t_node)
				* NODES[j]->num_links);
		make_links(info, NODES[j]->name, *i, j);
		j++;
	}
}
