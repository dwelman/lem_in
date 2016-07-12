/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 21:29:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/12 15:17:54 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_node(t_list *list, t_node *node)
{
	t_list	*crawl;

	crawl = list;
	while (crawl != NULL)
	{
		if (ft_strcmp((char *)crawl->data, node->name) == 0)
			return (0);
		crawl = crawl->next;
	}
	return (1);
}

int		search(t_info *info, t_node *node, t_node *goal)
{
	int	i;
	t_list	*crawl;

	i = 0;
	ft_printf("NODE ==== %s, links = %d\n", node->name, node->num_links);
	while (i < node->num_links)
	{
		if (ft_strcmp(node->name, goal->name) == 0)
		{
			crawl = info->checked;
			while (crawl != NULL)
			{
				ft_printf("already checked - %s\n", (char *)crawl->data);
				crawl = crawl->next;
			}
			return (1);
		}
		else
			ft_lstpush(&info->checked, ft_lstnew((void*)ft_strdup(node->name)));
		if (node->links[i] != NULL)
		{
			ft_printf("link = %s\n", node->links[i]->name);
			if (check_node(info->checked, node->links[i]) == 1)
				info->ret = search(info, node->links[i], goal);
		}
		i++;
		free(ft_lstpop(&info->checked));
	}
	return (info->ret);
}

void	find_paths(t_info *info)
{
	int	i;

	while (i < START->num_links)
	{
		if (info->checked != NULL)
			ft_lstdel(info->checked);
		info->checked = NULL;
		ft_lstappend(&info->checked, ft_lstnew((void *)START->name));
		info->ret = 0;
		if (search(info, START->links[i], info->end))
			ft_printf("%s%s = SUCCESS\n%s", "\x1B[32m", START->links[i]->name, "\x1B[37m");
		else
			ft_printf("%s%s = FAILURE\n%s", "\x1B[31m", START->links[i]->name, "\x1B[37m");
		i++;
	}
}
