/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:45:46 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/15 20:17:15 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Searches two paths, returning 1 if the two paths have matching nodes besides
*/

int		find_matching(t_list *p1, t_list *p2)
{
	t_list	*crawl_1;
	t_list	*crawl_2;
	int		i;

	i = 0;
	crawl_1 = p1;
	crawl_2 = p2;
	while (crawl_1 != NULL && crawl_2 != NULL)
	{
		if (i > 1 && crawl_1->next != NULL && crawl_2->next != NULL)
			if (ft_strcmp((char *)crawl_1->data, (char *)crawl_2->data) == 0)
				return (1);
		i++;
		if (crawl_1 != NULL)
			crawl_1 = crawl_1->next;
		if (crawl_2 != NULL)
			crawl_2 = crawl_2->next;
	}
	return (0);
}

/*
** Compares two paths, removing the longest one if the paths share any nodes
*/

int		cmp_paths(t_list *p1, t_list *p2, int index_1, int index_2)
{
	int	count_1;
	int	count_2;
	
	count_1 = 0;
	count_2 = 0;
	t_list	*crawl;

	/*crawl = p1;
	while (crawl != NULL)
	{
		ft_printf("p1 = %s\n", (char *)crawl->data);
		crawl = crawl->next;
	}
	crawl = p2;
	while (crawl != NULL)
	{
		ft_printf("p2 = %s\n", (char *)crawl->data);
		crawl = crawl->next;
	}*/
	if (find_matching(p1, p2) == 1)
	{
		count_1 = count_path(p1);
		count_2 = count_path(p2);
		if (count_1 < count_2)
			return (index_1);
		else if (count_2 < count_1)
			return (index_2);
		else
			return (-1);
	}
	else
		return (-1);
}

/*
** Removes paths with intersecting nodes to reduce the amount of paths and
** remove redundant paths, it keeps the shortest paths
*/

void	rm_intersect(t_info *info)
{
	t_list	*crawl;
	t_list	*trav;
	t_list	*temp;
	int		i;
	int		k;
	int		rem;

	crawl = info->paths;
	i = 0;
	rem = 0;
	while (crawl != NULL)
	{
		k = i;
		if (crawl->next != NULL)
		{
			trav = crawl->next;
			while (trav != NULL && k < count_path(trav))
			{
				ft_printf("TMP\n");
				temp = (t_list *)trav->data;
				ft_printf("CMP\n");
				rem = cmp_paths((t_list *)crawl->data, temp, i, k);
				printf("Rem = %d\n", rem);
				if (rem != -1)
				{
					ft_lst_removeindex(&info->paths, rem);
					if (rem == i)
						crawl = info->paths;
				}
				else
				{
					trav = trav->next;
					k++;
				}
				print_paths(info->paths);
				/*temp = (t_list *)crawl->data;
				ft_printf("crawl->data = %s\n", (char *)temp->data);
				temp = (t_list *)trav->data;
				ft_printf("temp->data = %s\n", (char *)temp->data);	*/
				if (trav != NULL)
					trav = trav->next;
				//k++;
			}
		}
		crawl = crawl->next;
		i++;
	}	
}
