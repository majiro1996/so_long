/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:47:35 by manujime          #+#    #+#             */
/*   Updated: 2023/04/13 15:33:25 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"

typedef struct s_point
{
	int		y;
	int		x;
}		t_point;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*man;
	char		**map;
	int			move_count;
	int			total_collect;
	int			current_collect;
	int			current_y;
	int			current_x;
	int			size_y;
	int			size_x;
	int			exit;
	int			key_pressed;
}		t_game;

//map_check
char	**ft_map_check(char *mapfile);
int		ft_el_count(char **map, char el);
//map_loader
int		ft_count_y(char *mapfile);
char	**ft_charge_map(char *mapfile);
void	ft_data_init(t_game *game, char **map);
//path
int		ft_path(char **map);
t_point	ft_get_player_yx(char **map);
//utils
void	ft_window(t_game *game);

#endif