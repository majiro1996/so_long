/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:47:35 by manujime          #+#    #+#             */
/*   Updated: 2023/04/12 19:10:43 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int		y;
	int		x;
}		t_point;

typedef struct s_game
{
	char	**map;
	int		move_count;
	int		total_collect;
	int		current_collect;
	int		current_y;
	int		current_x;
	int		next_y;
	int		next_x;
}		t_game;

//map_check
char	**ft_map_check(char *mapfile);
//map_loader
int		ft_count_y(char *mapfile);
char	**ft_charge_map(char *mapfile);
//path
int		ft_path(char **map);

#endif