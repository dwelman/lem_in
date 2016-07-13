/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 21:29:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/13 15:28:56 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Checks if a node is on the list of currently checked nodes, ensuring no
** node is visited twice
*/

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

/*
** A recursive algorithm 

int		search(t_info *info, t_node *node, t_node *goal)
{
	int	i;
	t_list	*crawl;

	i = 0;
	while (i < node->num_links)
	{
		if (ft_strcmp(node->name, goal->name) == 0)
		{
			ft_lstpush(&info->checked, ft_lstnew((void*)ft_strdup(node->name)));
			crawl = info->checked;
			ft_printf("\n");
			while (crawl != NULL)
			{
				ft_printf("path = %s\n", (char *)crawl->data);
				crawl = crawl->next;
			}
			ft_lstappend(&info->paths, ft_lstnew((void *)info->checked));
			info->ret = 1;
			i = node->num_links;
		}
		else
			ft_lstpush(&info->checked, ft_lstnew((void*)ft_strdup(node->name)));
		if (node->links[i] != NULL)
			if (check_node(info->checked, node->links[i]) == 1)
				info->ret = search(info, node->links[i], goal);
		i++;
		free(ft_lstpop(&info->checked));
	}
	return (info->ret);
}

void	find_paths(t_info *info)
{
	int	i;

	i = 0;
	info->paths = NULL;
	while (i < START->num_links)
	{
		info->ret = 0;
		info->checked = NULL;
		ft_lstappend(&info->checked, ft_lstnew((void *)START->name));
		if (search(info, START->links[i], info->end))
			ft_printf("%s%s = SUCCESS\n%s", "\x1B[32m", START->links[i]->name, "\x1B[37m");
		else
			ft_printf("%s%s = FAILURE\n%s", "\x1B[31m", START->links[i]->name, "\x1B[37m");
		i++;
	}
	/*t_list	*crawl;
	t_list	*temp;

	crawl = info->paths;
	while (crawl != NULL)
	{
		temp = (t_list *)crawl->data;
		while (temp != NULL)
		{
			ft_printf("HAI\n");
			//ft_printf("%s\n", (char *)temp->data);
			temp = temp->next;
		}
		crawl = crawl->next;
	}*/
}
