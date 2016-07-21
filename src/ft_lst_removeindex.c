/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_removeindex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 15:12:35 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 11:39:27 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
			{
				*list = crawl->next;
				free(crawl);
				return ;
			}
			else
			{
				prev->next = crawl->next;
				if (crawl->data)
					free(crawl->data);
				free(crawl);
				return ;
			}
		}
		else
		{
			prev = crawl;
			crawl = crawl->next;
			i++;
		}
	}
}
