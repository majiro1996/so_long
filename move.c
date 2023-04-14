/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:00:30 by manujime          #+#    #+#             */
/*   Updated: 2023/04/14 20:53:52 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_left(t_game *game)
{
	if (game->map[game->current_y][game->current_x - 1] == '1')
		return ;
	if (game->map[game->current_y][game->current_x - 1] == 'C')
		ft_take_potion(game, game->current_y, game->current_x - 1);
	game->player->instances[0].x -= 32;
	game->current_x -= 1;
	game->move_count++;
	game->key_pressed = 1;
	ft_printf("Move count: %d\n", game->move_count);
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->current_y][game->current_x + 1] == '1')
		return ;
	if (game->map[game->current_y][game->current_x + 1] == 'C')
		ft_take_potion(game, game->current_y, game->current_x + 1);
	game->player->instances[0].x += 32;
	game->current_x += 1;
	game->move_count++;
	game->key_pressed = 1;
	ft_printf("Move count: %d\n", game->move_count);
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->current_y - 1][game->current_x] == '1')
		return ;
	if (game->map[game->current_y - 1][game->current_x] == 'C')
		ft_take_potion(game, game->current_y - 1, game->current_x);
	game->player->instances[0].y -= 32;
	game->current_y -= 1;
	game->move_count++;
	game->key_pressed = 1;
	ft_printf("Move count: %d\n", game->move_count);
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->current_y + 1][game->current_x] == '1')
		return ;
	if (game->map[game->current_y + 1][game->current_x] == 'C')
		ft_take_potion(game, game->current_y + 1, game->current_x);
	game->player->instances[0].y += 32;
	game->current_y += 1;
	game->move_count++;
	game->key_pressed = 1;
	ft_printf("Move count: %d\n", game->move_count);
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;
	t_game	*game;

	game = param;
	mlx = game->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (!game->key_pressed)
	{
		if (mlx_is_key_down(mlx, MLX_KEY_UP))
			ft_move_up(game);
		if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
			ft_move_down(game);
		if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
			ft_move_left(game);
		if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
			ft_move_right(game);
	}
	else if (!mlx_is_key_down(game->mlx, MLX_KEY_UP)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_the_end(game);
}
