/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:55:16 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/19 10:20:07 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ant	*make_ant(int num, t_list *path)
{
	t_ant	*ret;

	ret = (t_ant *)malloc(sizeof(t_ant));
	ret->number = num;
	ret->path = path;
	ret->crawl = path;
	return (ret);
}
