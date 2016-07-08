/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:17:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/08 18:24:39 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Counts how many nodes will be in the array
*/

static int		count_nodes(t_info *info, int i)
{
	int	count;

	count = 0;
	while (ft_strchr(info->input[i], '-') == NULL && info->input[i] != NULL)
	{
		if (ft_strchr(info->input[i], '#') == NULL)
			count++;
		i++;
	}
	if (count == 0)
		error();
	return (count);
}

/*
** Fills the nodes in the array woth specific data
*/

void			fill_data(t_info *info, char **arr, int j)
{
	if (arr[0])
		info->nodes[j]->name = arr[0];
	else
		error();
	if (arr[1])
		info->nodes[j]->x = ft_atoi(arr[1]);
	else
		error();
	if (arr[2])
		info->nodes[j]->y = ft_atoi(arr[2]);
	else
		error();
}

/*
** Populates the array of all rooms
*/

void			fill_nodes(t_info *info, int *i)
{
	char	**arr;
	int		j;

	j = 0;
	arr = NULL;
	info->num_rooms = count_nodes(info, *i);
	info->nodes = (t_node **)malloc(sizeof(t_node) * info->num_rooms);
	while (ft_strchr(info->input[*i], '-') == NULL)
	{
		if (*info->input[*i] != '#')
		{
			arr = ft_strsplit(info->input[*i], ' ');
			info->nodes[j] = new_node();
			fill_data(info, arr, j);
			j++;
		}
		*i += 1;
	}
	connect_nodes(info, i);
}
