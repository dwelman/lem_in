/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:12:26 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/19 09:14:08 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	t_info	info;

	info.checked = NULL;
	info.short_paths = NULL;
	read_info(&info);
	ft_printf("hi\n");
	find_paths(&info);
	rm_intersect(&info);
	return (0);
}
