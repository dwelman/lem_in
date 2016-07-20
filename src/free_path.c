/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:41:58 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/20 15:12:32 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_path(t_list *path)
{
	t_list	*crawl;
	t_list	*trav;
	t_list	*temp;

	crawl = path;
	while (crawl != NULL)
	{
		temp = crawl;
		crawl = crawl->next;
		free(temp);
	}
	path = NULL;
}
