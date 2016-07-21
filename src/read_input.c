/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:15:53 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 08:17:51 by daviwel          ###   ########.fr       */
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
	first = ft_lstnew((void *)ft_strdup(line));
	free(line);
	while (get_next_line(0, &line))
	{
		list = ft_lstnew((void *)ft_strdup(line));
		ft_lstappend(&first, list);
		free(line);
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
** stores the input into relevant variables, also checks that the map has links
*/

void	interpret_input(t_info *info)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (info->input[i])
	{
		if (ft_strchr(info->input[i], '-') != NULL)
			count++;
		i++;
	}
	if (count == 0)
		error();
	info->num_ants = ft_atoi(info->input[0]);
	if (info->num_ants <= 0)
		error();
	i = -1;
	while (info->input[++i])
		ft_printf("%s\n", info->input[i]);
	ft_printf("\n");
	i = 1;
	fill_nodes(info, &i);
}

/*
** Ensures that the map has a start and end point
*/

void	check_map(char **arr, int length)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < length)
	{
		if (ft_strcmp(arr[i], "##start") == 0)
		{
			start++;
			if (ft_strcmp(arr[i + 1], "##end") == 0)
				error();
		}
		if (ft_strcmp(arr[i], "##end") == 0)
		{
			end++;
			if (ft_strcmp(arr[i + 1], "##start") == 0)
				error();
		}
		i++;
	}
	if (!(start == 1 && end == 1))
		error();
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
	check_map(info->input, length);
	ft_lstdel(list);
	interpret_input(info);
	free_arr(info->input);
	info->input = NULL;
}
