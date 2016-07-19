/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:45:46 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/19 12:04:31 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Searches two paths, returning 1 if the two paths have matching nodes besides
*/

int			find_matching(t_list *p1, t_list *p2)
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
** Compares two paths, removing the longest one if the paths share any nodes
*/

int			cmp_paths(t_list *p1, t_list *p2, int index_1, int index_2)
{
	int	count_1;
	int	count_2;

	count_1 = 0;
	count_2 = 0;
	if (find_matching(p1, p2) == 1)
	{
		count_1 = count_path(p1);
		count_2 = count_path(p2);
		if (count_1 < count_2)
		{
			return (index_2);
		}
		else if (count_2 <= count_1)
			return (index_1);
		else
			return (-1);
	}
	else
		return (-1);
}

/*
** Reset list traversal pointers and indexes to start -
** subfunction for rm_intersect
*/

static void	restart(t_info *info, t_inter *in)
{
	if (info->paths != NULL)
		in->cur = ((t_list*)info->paths);
	if (info->paths->next != NULL)
		in->test = ((t_list*)info->paths->next);
	in->c = 0;
	in->t = 1;
}

/*
** Check value of r to remove the correct element from the list -
** subfunction for rm_intersect
*/

static void	check_r(t_info *info, t_inter *in)
{
	if (in->r == in->c)
	{
		ft_lst_removeindex(&info->paths, in->c);
		restart(info, in);
	}
	else if (in->r == in->t)
	{
		ft_lst_removeindex(&info->paths, in->t);
		restart(info, in);
	}
	else
	{
		in->test = in->test->next;
		in->t++;
	}
}

/*
** Removes paths with intersecting nodes to reduce the amount of paths and
** remove redundant paths, it keeps the shortest paths
*/

void		rm_intersect(t_info *info)
{
	t_inter	in;

	restart(info, &in);
	while (in.cur && in.cur->next && in.c != in.t)
	{
		in.r = cmp_paths((t_list*)in.cur->data,
			(t_list*)in.test->data, in.c, in.t);
		check_r(info, &in);
		if (in.test == NULL)
		{
			if (in.cur->next)
				in.cur = in.cur->next;
			in.c++;
			in.test = in.cur->next;
			in.t = in.c + 1;
		}
	}
}
