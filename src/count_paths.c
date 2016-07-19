/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:55:01 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/19 14:55:43 by daviwel          ###   ########.fr       */
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

