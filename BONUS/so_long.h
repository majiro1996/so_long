/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:47:35 by manujime          #+#    #+#             */
/*   Updated: 2023/04/18 16:54:09 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"

typedef struct s_point
{
	int		y;
	int		x;
}		t_point;

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*potion;
	mlx_texture_t	*player;
	mlx_texture_t	*ladder;

}	t_textures;

typedef struct s_game
{
	mlx_image_t	*text;
	t_textures	*textures;
	mlx_t		*mlx;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	**potion;
	mlx_image_t	*player;
	mlx_image_t	*ladder;
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
int		ft_map_check(char *mapfile);
int		ft_el_count(char **map, char el);
//map_loader
int		ft_count_y(char *mapfile);
char	**ft_charge_map(char *mapfile);
void	ft_data_init(t_game *game, char **map, char *mapfile);
//path
int		ft_path(char **map);
t_point	ft_get_player_yx(char **map);
//render
void	ft_window(t_game *game);
//move
void	ft_hook(void *param);
//utils
void	ft_the_end(t_game *game);
void	ft_finish(t_game *game);
void	ft_collectible_list(t_game *game, mlx_image_t *image);
void	ft_take_potion(t_game *game, int y, int x);
//bonus
void	ft_render_counter(t_game *game);

#endif