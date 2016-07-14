/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:13:39 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/14 08:09:47 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *start_src)
{
	t_list	*trav;
	t_list	*new;
	char	*str;

	new = NULL;
	if (start_src)
	{
		trav = start_src;
		str = ft_strdup((char *)trav->data);
		new = ft_lstnew(str);
		trav = trav->next;
		while (trav)
		{
			str = ft_strdup((char *)trav->data);
			ft_lstappend(&new, ft_lstnew(str));
			trav = trav->next;
		}
	}
	return (new);
}
