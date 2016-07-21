/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:13:39 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/21 07:36:27 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	swap_paths(t_list *p1, t_list *p2)
{
	void	*data;

	data = p1->data;
	p1->data = p2->data;
	p2->data = data;
}

void	sort_paths(t_info *info)
{
	t_list	*p1;
	t_list	*p2;
	int		swap;

	swap = 1;
	while (swap)
	{
		swap = 0;
		p1 = info->paths;
		while (p1 && p1->next)
		{
			if (count_path((t_list*)p1->data)
				> count_path((t_list*)p1->next->data))
			{
				swap_paths(p1, p1->next);
				swap = 1;
			}
			p1 = p1->next;
		}
	}
}
