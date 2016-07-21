/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_removeindex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 15:12:35 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 15:21:57 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	first_node(t_list **list, t_list **crawl)
{
	t_list	*tc;

	tc = *crawl;
	*list = tc->next;
	free(*crawl);
	*crawl = NULL;
}

void	mid_node(t_list **list, t_list **prev, t_list **crawl)
{
	t_list *tc;
	t_list *pc;

	tc = *crawl;
	pc = *prev;
	pc->next = tc->next;
	if (tc->data)
		free(tc->data);
	free(*crawl);
	*crawl = NULL;
}

void	ft_lst_removeindex(t_list **list, int index)
{
	int		i;
	t_list	*crawl;
	t_list	*prev;

	i = 0;
	crawl = *list;
	prev = crawl;
	while (crawl != NULL)
	{
		if (i == index)
		{
			if (i == 0)
				first_node(list, &crawl);
			else
				mid_node(list, &prev, &crawl);
		}
		else
		{
			prev = crawl;
			crawl = crawl->next;
			i++;
		}
	}
}
