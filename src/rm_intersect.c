/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:45:46 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/18 16:36:16 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_path(t_list *list)
{
	t_list	*trav;

	trav = list;
	while (trav)
	{
		ft_printf("%s",(char*)trav->data);
		if (trav->next)
			ft_printf("-");
		else
			ft_putchar('\n');
		trav = trav->next;
	}
}

/*
** Searches two paths, returning 1 if the two paths have matching nodes besides
*/

int		find_matching(t_list *p1, t_list *p2)
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
				if (ft_strcmp((char *)crawl_1->data, (char *)crawl_2->data) == 0)
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

int		cmp_paths(t_list *p1, t_list *p2, int index_1, int index_2)
{
	int	count_1;
	int	count_2;
	
	count_1 = 0;
	count_2 = 0;
	t_list	*crawl;
	if (find_matching(p1, p2) == 1)
	{
		count_1 = count_path(p1);
		count_2 = count_path(p2);
		if (count_1 < count_2)
		{
			ft_printf("boop\n");
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
** Removes paths with intersecting nodes to reduce the amount of paths and
** remove redundant paths, it keeps the shortest paths
*/


void	rm_intersect(t_info *info)
{
	t_list	*cur;
	t_list	*test;
	int		c;
	int		t;
	int		r;

	if (info->paths != NULL)
		cur = ((t_list*)info->paths);
	if (info->paths->next != NULL)
		test = ((t_list*)info->paths->next);
	else
		return ;
	c = 0;
	t = 1;
	while (cur && cur->next)
	{
		ft_printf("==================WHILE===============\n");
		if (c == t)
			return ;
		r = cmp_paths((t_list*)cur->data ,(t_list*)test->data, c, t);
		printf("c = %d t = %d r = %d\n", c, t, r);
		if (r == c)
		{
			ft_printf("r == c\n");
			ft_lst_removeindex(&info->paths, c);
			cur = test;
			test = test->next;
		}
		else if (r == t)
		{
			ft_printf("r == t\n");
			test = test->next;
			ft_lst_removeindex(&info->paths, t);
		}
		else 
		{
			test = test->next;
			t++;
		}
		if (test == NULL)
		{
			if (cur->next)
				cur = cur->next;
			c++;
			test = cur->next;
			t = c + 1;
		}
		ft_printf("test : ");
		if (test)
			print_path(test->data);
		ft_printf("cur : ");
		if (cur)
			print_path(cur->data);
	}
	ft_printf("+++++++OUT++++++++++\n");
	print_paths(info->paths);
	ft_printf("+++++++END++++++++++\n");
}
