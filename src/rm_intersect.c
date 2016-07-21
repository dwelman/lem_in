/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:45:46 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 11:55:50 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Searches two paths, returning 1 if the two paths have matching nodes besides
*/

static int		find_matching(t_list *p1, t_list *p2)
{
	t_list	*crawl_1;
	t_list	*crawl_2;
	int		i;

	crawl_1 = p1;
	while (crawl_1 != NULL)
	{
		i = 0;
		crawl_2 = p2;
		while (crawl_2 != NULL && crawl_1 != NULL)
		{
			if (i > 0 && crawl_1->next != NULL && crawl_2->next != NULL)
				if (ft_strcmp((char *)crawl_1->data,
				(char *)crawl_2->data) == 0)
					return (1);
			i++;
			crawl_2 = crawl_2->next;
		}
		crawl_1 = crawl_1->next;
	}
	return (0);
}

/*
** Reset list traversal pointers and indexes to start -
** subfunction for rm_intersect
*/

static void		init(t_info *info, t_inter *in)
{
	if (info->paths != NULL)
		in->cur = ((t_list*)info->paths);
	if (info->paths->next != NULL)
		in->test = ((t_list*)info->paths->next);
	in->c = 0;
	in->t = 1;
}

/*
** Removes paths with intersecting nodes to reduce the amount of paths and
** remove redundant paths, it keeps the shortest paths
*/

void			rm_intersect(t_info *info)
{
	t_inter	in;

	init(info, &in);
	while (in.cur)
	{
		in.test = in.cur->next;
		in.t = in.c + 1;
		while (in.test)
		{
			if (find_matching((t_list*)in.cur->data, (t_list*)in.test->data))
			{
				in.test = in.test->next;
				ft_lst_removeindex(&info->paths, in.t);
			}
			else
			{
				in.test = in.test->next;
				in.t++;
			}
		}
		in.cur = in.cur->next;
		in.c++;
	}
}
