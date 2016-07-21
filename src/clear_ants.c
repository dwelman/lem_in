/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:58:23 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 11:55:41 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	clear_ants(t_list *ants)
{
	t_list	*crawl;

	crawl = ants;
	while (crawl != NULL)
	{
		free(crawl->data);
		crawl = crawl->next;
	}
}
