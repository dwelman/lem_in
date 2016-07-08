/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:15:53 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/08 14:41:27 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Stores the input in a linked list for later use
*/

t_list	*store_info(void)
{
	t_list	*list;
	t_list	*first;
	char	*line;

	get_next_line(0, &line);
	first = ft_lstnew((void *)line);
	while (get_next_line(0, &line))
	{
		list = ft_lstnew((void *)line);
		ft_lstappend(&first, list);
	}
	return (first);
}

/*
** Counts the elements in the linked list
*/

int		count_list(t_list *list)
{
	t_list	*crawl;
	int		i;

	crawl = list;
	i = 0;
	while (crawl != NULL)
	{
		crawl = crawl->next;
		i++;
	}
	return (i);
}

/*
** stores the input into relevant variables
*/

void	interpret_input(t_info *info)
{
	int	i;

	i = 0;
	info->num_ants = ft_atoi(info->input[i++]);
	if (info->num_ants <= 0)
		error();
	fill_nodes(info, &i);
}

/*
** Reads input into an array
*/

void	read_info(t_info *info)
{
	char	*line;
	t_list	*list;
	t_list	*crawl;
	int		length;
	int		i;

	i = 0;
	list = store_info();
	crawl = list;
	length = count_list(list);
	info->input = (char **)malloc(sizeof(char *) * length + 1);
	while (crawl != NULL)
	{
		info->input[i] = ft_strdup((char *)crawl->data);
		crawl = crawl->next;
		i++;
	}
	info->input[i] = NULL;
	interpret_input(info);
}
