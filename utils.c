/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:52:23 by manujime          #+#    #+#             */
/*   Updated: 2023/04/14 16:40:57 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_texures(t_game *game)
{
	game->textures->player = mlx_load_png("textures/player.png");
	game->textures->floor = mlx_load_png("textures/floor.png");
	game->textures->potion = mlx_load_png("textures/potion.png");
	game->textures->ladder = mlx_load_png("textures/ladder.png");
	game->textures->wall = mlx_load_png("textures/wall.png");
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;
	t_game	*game;

	game = param;
	mlx = game->mlx;
	if (!game->key_pressed)
		game->key_pressed = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		game->player->instances[0].y -= 32;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		game->player->instances[0].y += 32;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		game->player->instances[0].x -= 32;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		game->player->instances[0].x += 32;
	game->key_pressed = 0;
}

void	ft_render_player(t_game *game)
{
	if (!game->textures->player)
		exit(1);
	game->player = mlx_texture_to_image(game->mlx, game->textures->player);
	if (!game->player)
		exit(1);
	if (mlx_image_to_window(game->mlx, game->player, game->current_x * 32,
			game->current_y * 32) < 0)
		exit(1);
}

void	ft_fill_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			game->floor = mlx_texture_to_image(game->mlx, game->textures->floor);
			if (mlx_image_to_window(game->mlx, game->floor, j * 32,
					i * 32) < 0)
				exit(1);
			if (game->map[i][j] == '1')
			{
				game->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
				if (mlx_image_to_window(game->mlx, game->wall, j * 32,
						i * 32) < 0)
					exit(1);
			}
			else if (game->map[i][j] == 'C')
			{
				game->potion = mlx_texture_to_image(game->mlx, game->textures->potion);
				if (mlx_image_to_window(game->mlx, game->potion, j * 32,
						i * 32) < 0)
					exit(1);
			}
			else if (game->map[i][j] == 'E')
			{
				game->ladder = mlx_texture_to_image(game->mlx, game->textures->ladder);
				if (mlx_image_to_window(game->mlx, game->ladder, j * 32,
						i * 32) < 0)
					exit(1);
			}
			j++;
		}
		i++;
	}
}



void	ft_window(t_game *game)
{
	t_textures	textures;

	game->mlx = mlx_init(game->size_x * 32, game->size_y * 32,
			"so_long", false);
	if (!game->mlx)
	{
		ft_printf("Graphic error\n");
		exit(1);
	}
	game->textures = &textures;
	ft_load_texures(game);
	ft_fill_map(game);
	ft_render_player(game);
	mlx_loop_hook(game->mlx, &ft_hook, &game);
	mlx_loop(game->mlx);
	exit(0);
}
