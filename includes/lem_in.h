/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:12:40 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/21 15:24:46 by ddu-toit         ###   ########.fr       */
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
	int				has_ant;
	int				x;
	int				y;
}				t_node;

typedef struct	s_ant
{
	int			number;
	int			has_moved;
	int			at_end;
	t_list		*path;
	t_list		*crawl;
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
	t_list		*ants;
}				t_info;

typedef struct	s_inter
{
	t_list	*cur;
	t_list	*test;
	int		c;
	int		t;
	int		r;
}				t_inter;

typedef struct	s_control
{
	t_list	*path_crawl;
	t_list	*temp_path;
	t_node	*temp_node;
	int		cur_ant;
	int		prev_len;
	int		cur_len;
}				t_control;

void			check_links(t_info *info, int i);

void			sort_paths(t_info *info);

void			free_nodes(t_node **nodes, int node_count);

void			free_path(t_list *path);

void			free_node(t_node *node);

void			clear_ants(t_list *ants);

void			move_all_ants(t_list *ants, t_node *end);

void			reset_ants(t_list *ants);

void			control_ants(t_info *info);

int				move_ant(t_ant *ant, t_node *end);

t_ant			*make_ant(int num, t_list *path);

void			replace_nodes(t_info *info);

void			print_paths(t_list *paths);

void			rm_intersect(t_info *info);

void			ft_lst_removeindex(t_list **list, int index);

int				count_path(t_list *path);

void			trim_paths(t_info *info, t_list *paths);

void			rev_paths(t_list *paths);

void			read_info(t_info *info);

void			error(void);

t_node			*new_node(void);

void			free_arr(char **arr);

void			fill_nodes(t_info *info, int *i);

int				find_elem(t_node **nodes, char *name, int num);

void			connect_nodes(t_info *info, int *i);

void			find_paths(t_info *info);

#endif
