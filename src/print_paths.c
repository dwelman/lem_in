/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 17:55:11 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/15 20:17:17 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_paths(t_list *paths)
{
	int		i;
	t_list	*crawl;
	t_list	*temp;

	i = 0;
	//rev_paths(paths);
	crawl = paths;
	while (crawl != NULL)
	{
		temp = (t_list *)crawl->data;
		ft_printf("\nindex = %d\n", i);
		while (temp != NULL)
		{
			ft_printf("%s\n", (char *)temp->data);
			temp = temp->next;
		}
		crawl = crawl->next;
		i++;
	}
}
