/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 12:18:52 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 13:33:55 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_links(t_info *info, int i)
{
	char	**arr;
	t_node	*node;
	int		k;

	k = i;
	while (info->input[k] != NULL)
	{
		arr = ft_strsplit(info->input[k], '-');
		if (arr[0] == NULL || arr[1] == NULL)
			error();
		if (find_elem(info->nodes, arr[0], info->num_rooms) == -1)
			error();
		if (find_elem(info->nodes, arr[1], info->num_rooms) == -1)
			error();
		free_arr(arr);
		k++;
	}
}
