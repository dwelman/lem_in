/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 08:50:04 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/14 09:35:19 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This function reverses a specific list
*/

t_list	*rev_list(t_list *list)
{
	t_list	*new;
	t_list	*crawl;

	crawl = list;
	new = NULL;
	while (crawl != NULL)
		ft_lstpushpop(&crawl, &new);
	free(crawl);
	return (new);
}

/*
** As paths are stored in reverse order, this function reverses them so that the
** paths can be used by the ants
*/

void	rev_paths(t_list *paths)
{
	t_list	*crawl;

	crawl = paths;
	while (crawl != NULL)
	{
		crawl->data = (void *)rev_list((t_list *)crawl->data);
		crawl = crawl->next;
	}
}
