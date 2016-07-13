/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:12:40 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/13 13:45:04 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# define NODES info->nodes
# define START info->start

typedef struct	s_connect
{
	int			i;
	int			k;
	int			j;
}				t_connect;

typedef struct	s_node
{
	char			*name;
	int				num_ants;
	int				num_links;
	struct s_node	**links;
	int				is_mid_room;
	int				x;
	int				y;
}				t_node;

typedef struct	s_ant
{
	int			number;
	t_node		*room;
}				t_ant;

typedef struct	s_info
{
	int			num_ants;
	int			num_rooms;
	int			ret;
	char		**input;
	t_node		**nodes;
	t_node		*start;
	t_node		*end;
	t_list		*checked;
	t_list		*paths;
}				t_info;

void			read_info(t_info *info);

void			error(void);

t_node			*new_node(void);

void			free_arr(char **arr);

void			fill_nodes(t_info *info, int *i);

int				find_elem(t_node **nodes, char *name, int num);

void			connect_nodes(t_info *info, int *i);

void			find_paths(t_info *info);

#endif
