/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:12:26 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/19 10:06:21 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	t_info	info;

	info.checked = NULL;
	info.short_paths = NULL;
	info.ants = NULL;
	read_info(&info);
	find_paths(&info);
	rm_intersect(&info);
	replace_nodes(&info);
	control_ants(&info);
	return (0);
}
