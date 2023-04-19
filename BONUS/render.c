/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:52:23 by manujime          #+#    #+#             */
/*   Updated: 2023/04/19 17:06:11 by manujime         ###   ########.fr       */
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
	game->textures->enemy_1 = mlx_load_png("textures/holes.png");
	game->textures->enemy_2 = mlx_load_png("textures/holes_2.png");
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

/*renders all the sprites in the game besides the floor tile and the player*/
void	ft_fill_rest(t_game *game, int y, int x)
{
	mlx_image_t	*aux;

	if (game->map[y][x] == '1')
	{
		game->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
		if (mlx_image_to_window(game->mlx, game->wall, x * 32,
				y * 32) < 0)
			exit(1);
	}
	else if (game->map[y][x] == 'C')
	{
		aux = mlx_texture_to_image(game->mlx, game->textures->potion);
		if (mlx_image_to_window(game->mlx, aux, x * 32,
				y * 32) < 0)
			exit(1);
		ft_collectible_list(game, aux);
	}
	else if (game->map[y][x] == 'E')
	{
		game->ladder = mlx_texture_to_image(game->mlx, game->textures->ladder);
		if (mlx_image_to_window(game->mlx, game->ladder, x * 32,
				y * 32) < 0)
			exit(1);
	}
}

/*renders all the tiles in the game*/
void	ft_fill_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			game->floor = mlx_texture_to_image(game->mlx,
					game->textures->floor);
			if (mlx_image_to_window(game->mlx, game->floor, x * 32,
					y * 32) < 0)
				exit(1);
			else
			{
				ft_fill_rest(game, y, x);
				ft_render_hole(game, y, x);
				ft_render_tentacles(game, y, x);
			}
			x++;
		}
		y++;
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
	mlx_loop_hook(game->mlx, &ft_hook, game);
	mlx_loop(game->mlx);
	exit(0);
}
