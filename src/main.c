/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:12:26 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/20 16:42:59 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	t_info	info;
	t_list	*crawl;

	info.checked = NULL;
	info.ants = NULL;
	read_info(&info);//fix leaks
	find_paths(&info);//fix leaks
	ft_printf("lel\n");
	sort_paths(&info);
	rm_intersect(&info);//fix leaks
	replace_nodes(&info);//you're good buddy

	t_list	*temp;
	//t_list	*crawl;
	t_node	*node;

	temp = info.paths;
	while (temp != NULL)
	{
		crawl = (t_list *)temp->data;
		while (crawl != NULL)
		{
			node = (t_node *)crawl->data;
			ft_printf("%s\t", node->name);
			crawl = crawl->next;
		}
		temp = temp->next;
		ft_printf("\n");
	}
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
