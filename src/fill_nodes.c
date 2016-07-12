/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:17:34 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/11 12:32:37 by daviwel          ###   ########.fr       */
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
		NODES[j]->name = arr[0];
	else
		error();
	if (arr[1])
		NODES[j]->x = ft_atoi(arr[1]);
	else
		error();
	if (arr[2])
		NODES[j]->y = ft_atoi(arr[2]);
	else
		error();
}

/*
** Sets the start and end nodes
*/

void			set_bounds(t_info *info, int j, int start, int end)
{
	if (start == 1)
		info->start = NODES[j];
	if (end == 1)
		info->end = NODES[j];
}

/*
** Gets the start and end node indices
*/

void			get_bounds(t_info *info, int *i, int *start, int *end)
{
	if (ft_strcmp(info->input[*i], "##start") == 0)
	{
		*i += 1;
		*start = 1;
	}
	else
		*start = 0;
	if (ft_strcmp(info->input[*i], "##end") == 0)
	{
		*i += 1;
		*end = 1;
	}
	else
		*end = 0;
}

/*
** Populates the array of all rooms
*/

void			fill_nodes(t_info *info, int *i)
{
	char	**arr;
	int		j;
	int		start;
	int		end;

	j = 0;
	info->num_rooms = count_nodes(info, *i);
	NODES = (t_node **)malloc(sizeof(t_node) * info->num_rooms);
	while (ft_strchr(info->input[*i], '-') == NULL)
	{
		get_bounds(info, i, &start, &end);
		if (*info->input[*i] != '#')
		{
			arr = ft_strsplit(info->input[*i], ' ');
			NODES[j] = new_node();
			fill_data(info, arr, j);
			set_bounds(info, j, start, end);
			j++;
		}
		*i += 1;
	}
	connect_nodes(info, i);
	info->start->num_ants = info->num_ants;
}
