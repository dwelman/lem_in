/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 09:57:10 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/15 20:17:19 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Counts all nodes in a path
*/

int		count_path(t_list *path)
{
	t_list	*crawl;
	int		count;

	count = 0;
	crawl = path;
	while (crawl != NULL)
	{
		count++;
		crawl = crawl->next;
	}
	return (count);
}

/*
** This function looks through the paths and removes all but the shortest paths
** for each branch
*/

void	trim_paths(t_info *info, t_list *paths)
{
	int		count;
	char	*name;
	t_list	*crawl;
	t_list	*temp;
	t_list	*path;
	int		i;
	int		*k;

	crawl = paths;
	temp = NULL;
	i = 0;
	k = (int *)malloc(sizeof(int));
	rm_intersect(info);
	while (crawl != NULL)
	{
		*k = 0;
		count = count_path((t_list *)crawl->data);
		temp = (t_list *)crawl->data;
		name = (char *)temp->next->data;
		while (crawl != NULL && ft_strcmp(name, (char *)temp->next->data) == 0)
		{
			if (count_path((t_list *)crawl->data) <= count)
			{
				count = count_path((t_list *)crawl->data);
				*k = i;
			}
			i++;
			crawl = crawl->next;
			if (crawl != NULL)
				temp = (t_list *)crawl->data;
		}
		ft_printf("index = %d\n", *k); ////
		ft_lstappend(&info->short_paths, ft_lstnew((void *)k));
	}
}
