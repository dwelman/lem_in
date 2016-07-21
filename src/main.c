/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:12:26 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 11:26:58 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	t_info	info;
	t_list	*crawl;

	info.checked = NULL;
	info.ants = NULL;
	read_info(&info);
	find_paths(&info);
	sort_paths(&info);
	rm_intersect(&info);
	replace_nodes(&info);
	control_ants(&info);
	clear_ants(info.ants);
	crawl = info.paths;
	while (crawl != NULL)
	{
		free_path((t_list *)crawl->data);
		crawl = crawl->next;
	}
	free_nodes(info.nodes, info.num_rooms);
	return (0);
}
