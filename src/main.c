/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:12:26 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/20 14:40:31 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	t_info	info;

	info.checked = NULL;
	info.ants = NULL;
	read_info(&info);
	find_paths(&info);
	ft_printf("HAI\n");
	sort_paths(&info);
	rm_intersect(&info);
	replace_nodes(&info);

	t_list	*temp;
	t_list	*crawl;
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
	return (0);
}
