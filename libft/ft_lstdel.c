/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 07:41:18 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/21 07:44:36 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_lstdel(t_list *start)
{
	t_list	*trav;
	t_list	*prev;

	trav = start;
	while (trav)
	{
		if (trav->data)
		{
			free(trav->data);
			trav->data = NULL;
		}
		prev = trav;
		trav = trav->next;
		if (prev)
			free(prev);
		prev = NULL;
	}
	if (prev)
		free(prev);
	if (trav)
		free(trav);
}
